#define u64_t unsigned long long
#define s64_t signed long long

unsigned long long add64u(unsigned long long i, unsigned j)
{
	return i + j;
}
unsigned long long add64ul(unsigned long long i, unsigned long long j)
{
	return i + j;
}

unsigned long ex64lo(unsigned long long i)
{
	return (unsigned long)i;
}

unsigned long ex64hi(unsigned long long i)
{
	i = (i >> 32);
	return (unsigned long)i;
}

u64_t cvu64(unsigned i)
{
	return (unsigned long long) i;
}

u64_t cvul64(unsigned long i)
{
	return (unsigned long long) i;
}

int cmp64(u64_t i, u64_t j)
{
	if(i == j)
		return 1;
	else
		return 0;
}

int cmp64u(u64_t i, unsigned j)
{
	if(i == j)
		return 1;
	else
		return 0;
}

int cmp64ul(u64_t i, unsigned long j)
{
	if(i == j)
		return 1;
	else
		return 0;
}

u64_t make64(unsigned long lo, unsigned long hi)
{
	u64_t val = hi;
	val = (val << 32);
	val &= lo;
	return val;
}

u64_t sub64(u64_t i, u64_t j)
{
	return (i - j);
}

u64_t sub64u(u64_t i, unsigned j)
{
	return (i - j);
}

u64_t sub64ul(u64_t i, unsigned long j)
{
	return (i - j);
}

unsigned cv64u(u64_t i)
{
	return (unsigned) i;
}

unsigned long cv64ul(u64_t i)
{
	return (unsigned long) i;
}

u64_t add64(u64_t i, u64_t j)
{
	u64_t val = 0;
	val = (i + j);
	return val;
}

u64_t mul64u(unsigned long i, unsigned j)
{
	u64_t val = 0;
	val = (i * j);
	return val;
}

unsigned long div64u(u64_t i, unsigned j)
{
	u64_t val = 0;
	val = (i / j);
	return val;
}

unsigned rem64u(u64_t i, unsigned j)
{
	u64_t val = 0;
	val = (i / j);
	return val;
}


#define divnorm(num, den, sign) 		\
{						\
  if (num < 0) 					\
    {						\
      num = -num;				\
      sign = 1;					\
    }						\
  else 						\
    {						\
      sign = 0;					\
    }						\
						\
  if (den < 0) 					\
    {						\
      den = - den;				\
      sign = 1 - sign;				\
    } 						\
}

unsigned long divmodsi4(int modwanted, unsigned long num, unsigned long den);
unsigned long divmodsi4(int modwanted, unsigned long num, unsigned long den)
{						
  long int bit = 1;				
  long int res = 0;				
  while (den < num && bit && !(den & (1L<<31)))			       
    {
      den <<=1;					
      bit <<=1;					
    }						
  while (bit)
    {					
      if (num >= den)
	{				
	  num -= den;				
	  res |= bit;				
	}						
      bit >>=1;					
      den >>=1;					
    }						
  if (modwanted) return num;
  return res;
}

#define exitdiv(sign, res) if (sign) { res = - res;} return res;

long __modsi3 (long numerator, long denominator);
long __modsi3 (long numerator, long denominator)
{
  int sign = 0;
  long modul;
  if (numerator < 0) 
    {
      numerator = -numerator;
      sign = 1;
    }
  if (denominator < 0)
    {
      denominator = -denominator;
    }  
  
  modul =  divmodsi4 (1, numerator, denominator);
  if (sign)
    return - modul;
  return modul;
}

long __divsi3 (long numerator, long denominator);
long __divsi3 (long numerator, long denominator)
{
  int sign;
  long dividend;
  divnorm (numerator, denominator, sign);

  dividend = divmodsi4 (0,  numerator, denominator);
  exitdiv (sign, dividend);
}

long __umodsi3 (unsigned long numerator, unsigned long denominator);
long __umodsi3 (unsigned long numerator, unsigned long denominator)
{
	long modul;
	modul= divmodsi4 (1,  numerator, denominator);
	return modul;
}

long __udivsi3 (unsigned long numerator, unsigned long denominator);
long __udivsi3 (unsigned long numerator, unsigned long denominator)
{
	long dividend;
	dividend =   divmodsi4 (0, numerator, denominator);
	return dividend;
}

