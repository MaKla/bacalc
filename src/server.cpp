
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

using namespace std;

const int port = 2000;
const char *host = "127.0.0.1";

const char *errormap[] = {
		/*      NOERROR 0       */ "No error",
		/*	EPERM 1		*/ "Not super-user",
		/*	ENOENT 2	*/ "No such file or directory",
		/*	ESRCH 3		*/ "No such process",
		/*	EINTR 4		*/ "Interrupted system call",
		/*	EIO 5		*/ "I/O error",
		/*	ENXIO 6		*/ "No such device or address",
		/*	E2BIG 7		*/ "Arg list too long",
		/*	ENOEXEC 8	*/ "Exec format error",
		/*	EBADF 9		*/ "Bad file number",
		/*	ECHILD 10	*/ "No children",
		/*	EAGAIN 11	*/ "Resource temporarily unavailable",
		/*	ENOMEM 12	*/ "Not enough core",
		/*	EACCES 13	*/ "Permission denied",
		/*	EFAULT 14	*/ "Bad address",
		/*	ENOTBLK 15	*/ "Block device required",
		/*	EBUSY 16	*/ "Mount device busy",
		/*	EEXIST 17	*/ "File exists",
		/*	EXDEV 18	*/ "Cross-device link",
		/*	ENODEV 19	*/ "No such device",
		/*	ENOTDIR 20	*/ "Not a directory",
		/*	EISDIR 21	*/ "Is a directory",
		/*	EINVAL 22	*/ "Invalid argument",
		/*	ENFILE 23	*/ "Too many open files in system",
		/*	EMFILE 24	*/ "Too many open files",
		/*	ENOTTY 25	*/ "Not a typewriter",
		/*	ETXTBSY 26	*/ "Text file busy",
		/*	EFBIG 27	*/ "File too large",
		/*	ENOSPC 28	*/ "No space left on device",
		/*	ESPIPE 29	*/ "Illegal seek",
		/*	EROFS 30	*/ "Read only file system",
		/*	EMLINK 31	*/ "Too many links",
		/*	EPIPE 32	*/ "Broken pipe",
		/*	EDOM 33		*/ "Math arg out of domain of func",
		/*	ERANGE 34	*/ "Math result not representable",
		/*	ENOMSG 35	*/ "No message of desired type",
		/*	EIDRM 36	*/ "Identifier removed",
		/*	ECHRNG 37	*/ "Channel number out of range",
		/*	EL2NSYNC 38	*/ "Level 2 not synchronized",
		/*	EL3HLT 39	*/ "Level 3 halted",
		/*	EL3RST 40	*/ "Level 3 reset",
		/*	ELNRNG 41	*/ "Link number out of range",
		/*	EUNATCH 42	*/ "Protocol driver not attached",
		/*	ENOCSI 43	*/ "No CSI structure available",
		/*	EL2HLT 44	*/ "Level 2 halted",
		/*	EDEADLK 45	*/ "Deadlock condition",
		/*	ENOLCK 46	*/ "No record locks available",
					   "47",
					   "48",
					   "49",
		/* EBADE 50	*/ "Invalid exchange",
		/* EBADR 51	*/ "Invalid request descriptor",
		/* EXFULL 52	*/ "Exchange full",
		/* ENOANO 53	*/ "No anode",
		/* EBADRQC 54	*/ "Invalid request code",
		/* EBADSLT 55	*/ "Invalid slot",
		/* EDEADLOCK 56	*/ "File locking deadlock error",
		/* EBFONT 57	*/ "Bad font file fmt",
					   "58",
					   "59",
		/* ENOSTR 60	*/ "Device not a stream",
		/* ENODATA 61	*/ "No data (for no delay io)",
		/* ETIME 62	*/ "Timer expired",
		/* ENOSR 63	*/ "Out of streams resources",
		/* ENONET 64	*/ "Machine is not on the network",
		/* ENOPKG 65	*/ "Package not installed",
		/* EREMOTE 66	*/ "The object is remote",
		/* ENOLINK 67	*/ "The link has been severed",
		/* EADV 68		*/ "Advertise error",
		/* ESRMNT 69	*/ "Srmount error",
		/*	ECOMM 70	*/ "Communication error on send",
		/* EPROTO 71	*/ "Protocol error",
					   "72",
					   "73",
		/*	EMULTIHOP 74	*/ "Multihop attempted",
		/*	ELBIN 75	*/ "Inode is remote (not really error)",
		/*	EDOTDOT 76	*/ "Cross mount point (not really error)",
		/* EBADMSG 77	*/ "Trying to read unreadable message",
					   "78",
					   "79",
		/* ENOTUNIQ 80	*/ "Given log. name not unique",
		/* EBADFD 81	*/ "f.d. invalid for this operation",
		/* EREMCHG 82	*/ "Remote address changed",
		/* ELIBACC 83	*/ "Can't access a needed shared lib",
		/* ELIBBAD 84	*/ "Accessing a corrupted shared lib",
		/* ELIBSCN 85	*/ ".lib section in a.out corrupted",
		/* ELIBMAX 86	*/ "Attempting to link in too many libs",
		/* ELIBEXEC 87	*/ "Attempting to exec a shared library",
		/* ENOSYS 88	*/ "Function not implemented",
		/* ENMFILE 89      */ "No more files",
		/* ENOTEMPTY 90	*/ "Directory not empty",
		/* ENAMETOOLONG 91	*/ "File or path name too long",
		/* ELOOP 92     */ "Too many symbolic links",
				   "93",
				   "94",
		/* EOPNOTSUPP 95 */ "Operation not supported on transport endpoint",
		/* EPFNOSUPPORT 96 */ "Protocol family not supported",
				   "97",
				   "98",
				   "99",
				   "100",
				   "101",
				   "102",
				   "103",
		/* ECONNRESET 104 */ "Connection reset by peer",
		/* ENOBUFS 105 */ "No buffer space available",
		/* EAFNOSUPPORT 106 */ "Address family not supported by protocol",
		/* EPROTOTYPE 107 */ "Protocol wrong type for transport endpoint",
		/* ENOTSOCK 108 */  "Socket operation on non-socket",
		/* ENOPROTOOPT 109 */ "Protocol not available",
		/* ESHUTDOWN 110 */ "Cannot send after transport endpoint shutdown",
		/* ECONNREFUSED 111 */ "Connection refused",
		/* EADDRINUSE 112 */ "Address already in use",
		/* ECONNABORTED 113 */ "Connection aborted",
		/* ENETUNREACH 114 */ "Network is unreachable",
		/* ENETDOWN 115 */ "Network is down",
		/* ETIMEDOUT 116 */ "Connection timed out",
		/* EHOSTDOWN 117 */ "Host is down",
		/* EHOSTUNREACH 118 */ "No route to host",
		/* EINPROGRESS 119 */ "Operation now in progress",
		/* EALREADY 120 */ "Operation already in progress",
		/* EDESTADDRREQ 121 */ "Destination address required",
		/* EMSGSIZE 122 */ "Message too long",
		/* EPROTONOSUPPORT 123 */ "Protocol not supported",
		/* ESOCKTNOSUPPORT 124 */ "Socket type not supported",
		/* EADDRNOTAVAIL 125 */ "Cannot assign requested address",
		/* ENETRESET 126 */ "Network dropped connection because of reset",
		/* EISCONN 127 */ "Transport endpoint is already connected",
		/* ENOTCONN 128 */ "Transport endpoint is not connected",
		/* ETOOMANYREFS 129 */ "Too many references: cannot splice",
		/* EPROCLIM 130 */ "Process limit exceeded",
		/* EUSERS 131 */ "Too many users",
		/* EDQUOT 132 */ "Quota exceeded",
		/* ESTALE 133 */ "Stale NFS file handle",
		/* ENOTSUP 134 */   "134",
		/* ENOMEDIUM 135 */ "no medium",
		/* ENOSHARE 136 */   "No such host or network path",
		/* ECASECLASH 137 */ "Filename exists with different case"

};

const char max_amount_of_connections = 1;

int main() {

	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;

	// get a socket file descriptor
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd == -1) {
		cerr << "couldn't create inet socket";
		return 1;
	}

	my_addr.sin_family = AF_INET;         // host byte order
	my_addr.sin_port = htons(port);     // short, network byte order
	// inat_addr casts the given ip as char to 4 bytes IPv4
	my_addr.sin_addr.s_addr = inet_addr(host);
	//memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct

	// bind your socket. If e != 0 an error occures (if port is already in use)
	int e = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));

	if (e != 0) {
		perror("could not bind to socket: ");
	}

	listen(sockfd, max_amount_of_connections);


	socklen_t sin_size = sizeof(struct sockaddr_in);
	int new_fd = accept(sockfd, (struct sockaddr *)&remote_addr, &sin_size);

	char buf[20];
	string dest = "";

	int nRec;
	nRec = recv(sockfd, buf, 21, 0);

	if (nRec == -1) {
		perror("Error occured while recieving");
		return 1;
	}
	cout << "<(" << nRec << ") " << dest << endl;
	buf[nRec] = '\0';
	// Hier landen alle gesendeten Daten (also auch von mehreren send()-Aufrufen)
	dest.append(buf);


	//delete [] buf;

	cout << dest << endl;

	return 0;
}
