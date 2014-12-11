	pid = fork();
	if (pid == -1) {
		printf("Fork error\n");
		exit(EXIT_FAILURE);
	}
	else if (!pid) {
		// child process
		printf("I am the child process.\n");
		execv("/usr/bin/python2.6", NULL);
	}
	else {
		// parent process
		printf("I am the parent process.\n");
	}
	wait();

