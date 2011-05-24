unsigned char inb(unsigned int *port)
{
	unsigned char data;
	data = *port;
	return data;
}

void outb(unsigned int *port, char value)
{
	*port = value;
	return;
}

unsigned int inl(unsigned int *port)
{
	return (unsigned int)*port;
}

void outl(unsigned int *port, int value)
{
	*port = value;
	return;
}

unsigned int inw(unsigned int *port)
{
	return (unsigned int)*port;
}

void outw(unsigned int *port, int value)
{
	*port = value;
	return;
}