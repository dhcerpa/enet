#include <Windows.h>
#include <stdio.h>

void TestLibrary(const char* libraryName)
{
	HMODULE handle = LoadLibrary(libraryName);
	if (handle != NULL)
	{
		printf("%s found\n", libraryName);
		char buf[256] = { 0 };
		GetModuleFileName(handle, buf, 256);
		printf("%s path: %s\n", libraryName, buf);

		FARPROC initializeFunc = GetProcAddress(handle, "enet_initialize");
		if (initializeFunc != NULL)
		{
			printf("enet_initialize found\n");
		}
		else
		{
			printf("enet_initialize not found\n");
		}
	}
	else
	{
		printf("%s not found\n", libraryName);
	}
}

int main(int argc, char** args)
{
	TestLibrary("ENetX86.dll");
	TestLibrary("ENetX64.dll");

	getc(stdin);
	return 0;
}

