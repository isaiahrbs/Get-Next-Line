
//*-------------------------------------------------//
//*-------------------testing #1--------------------//
//*-------------------------------------------------//
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	// Open test file in read-only mode
	if (fd < 0)
	{
		perror("Error opening file");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	// Call get_next_line until it returns NULL
	{
		printf("Line: %s", line);
		free(line);
		// Free the memory allocated by get_next_line
	}

	close(fd); // Close the file after reading
	return 0;

//*-------------------------------------------------//
//*-------------------testing #2--------------------//
//*-------------------------------------------------//

int main(void)
{
	char *line;

	printf("Type something (Ctrl+D to end):\n");

	// Continuously call get_next_line with fd = 0 (standard input)
	while ((line = get_next_line(0)) != NULL) {
		printf("Output: %s", line); // Print the line received
		free(line); // Free the memory allocated by get_next_line
	}

	printf("\nEnd of input\n");
	return 0;
}
