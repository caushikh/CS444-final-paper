/*
 * Taken from MSDN CreateProcess example
*/

// Start the child process
if (!CreateProcess( NULL,	// No module name (use command line)
	argv[1],	// Command line
	NULL,		// Process handle not inheritable
	NULL,		// Thread handle not inheritable
	FALSE,		// Set handle inheritance to FALSE
	0,		// No creation flags
	NULL,		// Use parent's environment block
	NULL,		// Use parent's starting directory
	&si,		// Pointer to STARTUPINFO structure
	&pi )		// Pointer to PROCESS_INFORMATION structure
)
{
	printf("CreateProcess failed (%d).\n", GetLastError() );
	return;
}

// Wait until child process exits
WaitForSingleObject(pi.hProcess, INFINITE);

