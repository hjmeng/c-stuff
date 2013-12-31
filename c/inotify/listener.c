/* Adapted from IBM developerWorks tutorial:
 * http://www.ibm.com/developerworks/linux/library/l-ubuntu-inotify/index.html
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>

#define EVENT_SIZE 	( sizeof(struct inotify_event) )
#define BUF_LEN 	( 1024 * ( EVENT_SIZE + 16) )

char* file(const struct inotify_event *event);

int main(int argc, char *argv[]) {
	printf("EVENT_SIZE: %d\n", EVENT_SIZE);
	printf("BUF_LEN: %d\n", BUF_LEN);

	int length, i = 0;
	int fd, wd;
	char buffer[BUF_LEN];

	fd = inotify_init(); // initialize file descriptor associated with a new inotify event queue

	if ( fd < 0 )
		perror("inotify_init");

	// add watch to the inotify instance
	wd = inotify_add_watch(fd, "./",
			IN_MODIFY | IN_CREATE | IN_DELETE );
	length = read(fd, buffer, BUF_LEN);
	printf("length is %d\n", length);

	if (length < 0)
		perror("read");

	while (i < length) {
		// event struct
		struct inotify_event *event = (struct inotify_event *) &buffer[i];

		if (event->len) {
			if (event->mask & IN_CREATE) // & is bitwise AND
				printf("The %s %s was created\n", file(event), event->name);
			else if (event->mask & IN_DELETE)
				printf("The %s %s was deleted\n", file(event), event->name);
			else if (event->mask & IN_MODIFY)
				printf("The %s %s was modified\n", file(event), event->name);

			printf("size of name field: %d\n", event->len);
			i += EVENT_SIZE + event->len;
			printf("i is %d\n", i);
		}
	}

	(void) inotify_rm_watch(fd, wd); // remove watch
	(void) close(fd); // close file descriptor

	return 0;
}

/* Determine if the event pertains ot a file or a directory */
char* file(const struct inotify_event *event) {
	if (event->mask & IN_ISDIR)
		return "directory";
	return "file";
}
