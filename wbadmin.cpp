#include "rpc/client.h"
#include <iostream>
#include <stdio.h>
// #include <conio.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

	int cont;
	string ip;
	int port;
	for(cont=0; cont < argc; cont++){
		if(cont == 1)
			ip = argv[cont];
		if(cont == 2)
			port = atoi(argv[cont]);
	}

	cout << "ip: " << ip << endl;
	cout << "port: " << port << endl;


	rpc::client c (ip, port);
	c.call("wbadmin");


	return 0;
}