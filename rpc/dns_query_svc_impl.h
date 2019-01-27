/**
* Resplendent RPCs Lab
* CS 241 - Fall 2018
*/

/**
* This file's main function is called by the server stub to implement the server
* logic.
*/

#define MAX_BYTES_RECV 22 // e.g. "123.123.123.123:65535"
#define MAX_BYTES_IPV4 16 // e.g. "123.123.123.123"
#define MAX_BYTES_PORT 6  // e.g. "65535"

/**
 * The code breaks down like this
 * 1. Create a socket to communicate through UDP
 * 2. Fill in a `sockaddr_in` with the data for host and port.
 * (hint: you may find the function `inet_pton` to be useful for the host and AF)
 * (extra hint: the wikibook/wikibook-project are good resources for the above)
 * 4. `sendto` a single packet with the hostname without the null byte from
 *`argp`
 * 5. `recvfrom` the server. The bytes you receive back will be the IP address
 *without the null byte. The maximum size of an IP address will be 15 bytes not
 *included the null byte.
 * 6. If the nameserver was unable to find the ipaddress (returning
 *-1.-1.-1.-1), return null otherwise return the ipaddress
 * (We assume that the returned string is either NULL or on the heap because we
 *free it later!)
 * Congrats you just implemented the guts of a DNS server! (Without some of the
 *string parsing)
 * Args:
 *      argp: the query as received from the client. holds the domain you are trying to resolve and will send to the nameserver 
 *      host: the ipv4 address of the authoritative nameserver aka `./authoritative_nameserver`. 
 *      port: the port of the authoritative nameserver aka `./authoritative_nameserver`.
 **/
char *contact_nameserver(query *argp, char *host, int port);

/**
* Given the query and the fulfilled ipv4_address, fill in the response struct.
* All strings and structs must be malloc'ed and addeded.
* If `ipv4_address` == NULL, then you must set the success flag correctly and
* the `host_ipv4_address` field is ignored, but should be a malloc'ed string for
* memory management purposes.
* If not, that field should point to the IP Address of the hostname
* Make sure to fill out the rest of the fields of the response struct!
*/
void create_response(query *argp, char *ipv4_address, response *res);
