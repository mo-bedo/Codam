# Webserv
This project revolves around the creation of an HTTP server, akin to building a personalized version of Nginx, Apache, or Lighttpd.

What is Webserv?
Webserv is a collaborative project at Codam that challenges participants to construct an HTTP server utilizing I/O Multiplexing atop an event loop.

In the mandatory portion, the server commences by reading a configuration file, potentially modeled after Nginx. This file includes crucial information such as hostname (IP/port), servername, index file, directory listing, URL redirect, location (vhost path), and other settings. It is expressly forbidden to employ fork for creating new non-CGI processes or spawning threads, as threads are unavailable in C++98.

For I/O Multiplexing, wherein the Kernel is informed about the desire to receive notifications regarding changes in a pre-specified list of file descriptors, we had to choose between select, poll, epoll, or kqueue. All socket reads or writes must traverse through poll() or its equivalent, ensuring robust server availability while adhering to the event loop.

HTTP requests undergo reading, parsing, processing, and are sent to a CGI if configured in the provided configuration file. Ultimately, a HTTP response is dispatched to the client, encompassing headers, body, and the correct HTTP status code.

In the bonus segment, additional features such as supporting cookies, session management, and handling multiple CGI instances are implemented.