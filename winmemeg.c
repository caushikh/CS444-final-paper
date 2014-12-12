/* taken from Operating System Concepts */
hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, // R/W access
	FALSE, // no inheritance
	TEXT("SharedObject")); // name of mapped file object
lpMapAddress = MapViewOfFile(hMapFile, // mapped object handle
	FILE_MAP_ALL_ACCESS, // read/write access
	0, // mapped view of entire file
	0,
	0);
UnmapViewOfFile(lpMapAddress);
CloseHandle(hMapFile);
