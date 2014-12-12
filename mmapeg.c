fd = shm_open(res_name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
if (fd < 0) {
	printf("The shared memory resource could not be created.\n");
	exit(EXIT_FAILURE);
}
ftruncate(fd, sizeof(struct resource));
res = (struct resource *) mmap(NULL, sizeof(struct resource),
	PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
close(fd);

