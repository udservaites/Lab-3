// Lab3_Key_Generator.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "winsock2.h"
#include "windows.h"
#include "iphlpapi.h"
#include "WS2tcpip.h"


#pragma comment(lib, "IPHLPAPI.lib")

#define WORKING_BUFFER_SIZE 15000
#define MAX_TRIES 3

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

void password1();
void password2();
void password3();
void password4();
void password5();


#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Rebecca Servaites Lab 3 Key Generator\n\n");
	password1();
	password2();
	password3();
	password4();
	password5();


	return 0;


}


void password1() {

	char password1[] = "ABCDEF123456";

	printf("Password 1: ");

	for (int i = 0; i < sizeof(password1)-1; i++) {
		password1[i] += 5;
		printf("%c", password1[i]);
	}

	printf("\n");

}

void password2() {

	char password2[] = "ARCHIEMILLER";

	printf("Password 2: ");
	for (int i = 0; i < sizeof(password2)-1; i++) {
		password2[i] -= i;
		printf("%c", password2[i]);
	}

	printf("\n");
}

void password3() {

	char password3[] = "GO FLYERS!!!";

	printf("Password 3: ");

	for (int i = 0; i < sizeof(password3)-1; i++) {
		printf("%c", password3[i] ^ i);
	}
	printf("\n");

}


void password4() {
	DWORD serialNumber = 0;

	if (GetVolumeInformation(_T("C:\\"), NULL, NULL, &serialNumber, NULL, NULL, NULL, NULL)) {
		_tprintf(_T("Password 4: %lu\n"), serialNumber);
	}

}

void password5() {
	DWORD dwSize = 0;
	DWORD dwRetVal = 0;
	unsigned int i = 0;
	PIP_ADAPTER_ADDRESSES pAddresses = NULL;
	ULONG outBufLen = WORKING_BUFFER_SIZE;

	pAddresses = (PIP_ADAPTER_ADDRESSES)malloc(outBufLen);


	GetAdaptersAddresses(2, NULL, NULL, pAddresses, &outBufLen);
	unsigned char password5[9];
	unsigned char password5Final[9];

	if (pAddresses->PhysicalAddressLength != 0) {
		//printf("Physical address: ");
		for (i = 0; i < (int)pAddresses->PhysicalAddressLength;
			i++) {
			if (i == (pAddresses->PhysicalAddressLength - 1)) {
				password5[i] = pAddresses->PhysicalAddress[i];
				//printf("%.2X", password5[i]);
				/*printf("%.2X\n",
					(int)pAddresses->PhysicalAddress[i]);*/
			}
			else
				password5[i] = pAddresses->PhysicalAddress[i];
			//printf("%.2X-", password5[i]);
			/*printf("%.2X-",
			(int)pAddresses->PhysicalAddress[i]);*/
		}

	}

	password5Final[0] = password5[3];
	password5Final[1] = password5[2];
	password5Final[2] = password5[1];
	password5Final[3] = password5[0];
	password5Final[4] = '\0';
	printf("Password 5: ");

	for (int i = 0; i < 4; i++){

		printf("%.2X", password5Final[i]);
	}
	 
	printf("\n\n");
}





