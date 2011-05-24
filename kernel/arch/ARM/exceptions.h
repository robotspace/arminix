#ifndef  EXCEPTIONS_H
#define EXCEPTIONS_H

void fail_undef(void);
void fail_pabt(void);
void fail_dabt(void);
void FIQ_handler(void);
void SWI_handler(void);

#endif  /* EXCEPTIONS_H */