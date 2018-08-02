













 
















 




 
typedef unsigned char       uint8;   
typedef unsigned short int  uint16;  
typedef unsigned long int   uint32;  
typedef unsigned long long  uint64;  

typedef char                int8;    
typedef short int           int16;   
typedef long  int           int32;   
typedef long  long          int64;   

typedef volatile int8       vint8;   
typedef volatile int16      vint16;  
typedef volatile int32      vint32;  
typedef volatile int64      vint64;  

typedef volatile uint8      vuint8;   
typedef volatile uint16     vuint16;  
typedef volatile uint32     vuint32;  
typedef volatile uint64     vuint64;  



 
typedef union
{
    uint32  DW;
    uint16  W[2];
    uint8   B[4];
    struct
    {
        uint32 b0: 1;
        uint32 b1: 1;
        uint32 b2: 1;
        uint32 b3: 1;
        uint32 b4: 1;
        uint32 b5: 1;
        uint32 b6: 1;
        uint32 b7: 1;
        uint32 b8: 1;
        uint32 b9: 1;
        uint32 b10: 1;
        uint32 b11: 1;
        uint32 b12: 1;
        uint32 b13: 1;
        uint32 b14: 1;
        uint32 b15: 1;
        uint32 b16: 1;
        uint32 b17: 1;
        uint32 b18: 1;
        uint32 b19: 1;
        uint32 b20: 1;
        uint32 b21: 1;
        uint32 b22: 1;
        uint32 b23: 1;
        uint32 b24: 1;
        uint32 b25: 1;
        uint32 b26: 1;
        uint32 b27: 1;
        uint32 b28: 1;
        uint32 b29: 1;
        uint32 b30: 1;
        uint32 b31: 1;
    };
} Dtype;    



 
typedef struct
{
    uint16 x;
    uint16 y;
} Site_t;



 
typedef struct
{
    uint16 W;       
    uint16 H;       
} Size_t;





 
typedef enum
{
     
    NonMaskableInt_IRQn          = -14,               
    HardFault_IRQn               = -13,               
    SVCall_IRQn                  = -5,                
    PendSV_IRQn                  = -2,                
    SysTick_IRQn                 = -1,                

     
    Reserved16_IRQn              = 0,                 
    Reserved17_IRQn              = 1,                 
    Reserved18_IRQn              = 2,                 
    Reserved19_IRQn              = 3,                 
    Reserved20_IRQn              = 4,                 
    FTMRE_IRQn                   = 5,                 
    PMC_IRQn                     = 6,                 
    IRQ_IRQn                     = 7,                 
    I2C0_IRQn                    = 8,                 
    I2C1_IRQn                    = 9,                 
    SPI0_IRQn                    = 10,                
    SPI1_IRQn                    = 11,                
    UART0_IRQn                   = 12,                
    UART1_IRQn                   = 13,                
    UART2_IRQn                   = 14,                
    ADC_IRQn                     = 15,                
    ACMP0_IRQn                   = 16,                
    FTM0_IRQn                    = 17,                
    FTM1_IRQn                    = 18,                
    FTM2_IRQn                    = 19,                
    RTC_IRQn                     = 20,                
    ACMP1_IRQn                   = 21,                
    PIT_CH0_IRQn                 = 22,                
    PIT_CH1_IRQn                 = 23,                
    KBI0_IRQn                    = 24,                
    KBI1_IRQn                    = 25,                
    Reserved42_IRQn              = 26,                
    ICS_IRQn                     = 27,                
    WDOG_IRQn                    = 28,                
    PWT_IRQn                     = 29,                
    MSCAN_RX_IRQn                = 30,                
    MSCAN_TX_IRQn                = 31                 
} IRQn_t, IRQn_Type;





 
typedef enum
{
     
    NonMaskableInt_VECTORn           = 2,               
    HardFault_VECTORn                = 3,               
    SVCall_VECTORn                   = 11,                
    PendSV_VECTORn                   = 14,                
    SysTick_VECTORn                  = 15,                

     
    FTMRE_VECTORn                    = 21,                 
    PMC_VECTORn                      = 22,                 
    IRQ_VECTORn                      = 23,                 
    I2C0_VECTORn                     = 24,                 
    I2C1_VECTORn                     = 25,                 
    SPI0_VECTORn                     = 26,                
    SPI1_VECTORn                     = 27,                
    UART0_VECTORn                    = 28,                
    UART1_VECTORn                    = 29,                
    UART2_VECTORn                    = 30,                
    ADC_VECTORn                      = 31,                
    ACMP0_VECTORn                    = 32,                
    FTM0_VECTORn                     = 33,                
    FTM1_VECTORn                     = 34,                
    FTM2_VECTORn                     = 35,                
    RTC_VECTORn                      = 36,                
    ACMP1_VECTORn                    = 37,                
    PIT_CH0_VECTORn                  = 38,                
    PIT_CH1_VECTORn                  = 39,                
    KBI0_VECTORn                     = 40,                
    KBI1_VECTORn                     = 41,                

    ICS_VECTORn                      = 43,                
    WDOG_VECTORn                     = 44,                
    PWT_VECTORn                      = 45,                
    MSCAN_RX_VECTORn                 = 46,                
    MSCAN_TX_VECTORn                 = 47                 
} VECTORn_t;



 





 
 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 
















 






 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 





                 



  

                 













 

   



                 



























 


  #pragma system_include

 
 
 


  #pragma system_include

 

 

 

 

   

 

   #pragma system_include






 




 

 


 


 

 

 

 

 

 

 

 

 

 














 












 




















 










 




















































































































 


 










 





















 















 













 








 












 











 










 









 











 









 









 









 









 














 














 
















 












 








 











 










 









 









 









 









 









 









 









 









 







 




 









 




 





 
















































 













 






 


   

  







 





 





 




 



 





 




 



 












 
   






 
  #pragma language = save 
  #pragma language = extended
  #pragma language = restore






 





 




 





 








                 




















 


                 

 

 
 

 

 

 

 



                 






 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 





 

                                 













                 

                 

                 

                 
                 



                 
                                 


  #pragma language=save
  #pragma language=extended
  typedef long long _Longlong;
  typedef unsigned long long _ULonglong;
  #pragma language=restore

  typedef unsigned short int _Wchart;
  typedef unsigned short int _Wintt;



                 

typedef signed int  _Ptrdifft;
typedef unsigned int     _Sizet;

 

                 



 
  typedef struct __va_list
  {
    char  *_Ap;
  } __va_list;

  typedef __va_list __Va_list;


__intrinsic __nounwind void __iar_Atexit(void (*)(void));


  typedef struct
  {        
    unsigned int _Wchar;
    unsigned int _State;
  } _Mbstatet;



  typedef struct __FILE _Filet;


typedef struct
{        
  _Longlong _Off;     
  _Mbstatet _Wstate;
} _Fpost;




                 














 


  #pragma system_include





 






















































































 

 


  
 

   


  





  #pragma language=save 
  #pragma language=extended
  __intrinsic __nounwind void __iar_dlib_perthread_initialize(void  *);
  __intrinsic __nounwind void  *__iar_dlib_perthread_allocate(void);
  __intrinsic __nounwind void __iar_dlib_perthread_destroy(void);
  __intrinsic __nounwind void __iar_dlib_perthread_deallocate(void  *);



  #pragma segment = "__DLIB_PERTHREAD" 
  #pragma segment = "__DLIB_PERTHREAD_init" 









   
  void  *__iar_dlib_perthread_access(void  *);
  #pragma language=restore








     
  



   
    __intrinsic __nounwind void __iar_Locale_lconv_init(void);

  


  
  typedef void *__iar_Rmtx;
  
  
  __intrinsic __nounwind void __iar_system_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxunlock(__iar_Rmtx *m);

  __intrinsic __nounwind void __iar_file_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxunlock(__iar_Rmtx *m);

  
 
  __intrinsic __nounwind void __iar_clearlocks(void);



  



  


  typedef unsigned _Once_t;

  








                 


                 
  
  
    
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock(unsigned int);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock(unsigned int);

  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Initdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Dstdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockdynamicfilelock(__iar_Rmtx *);
  
  

                 


                 







 
 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 






                 
typedef _Sizet size_t;

typedef unsigned int __data_size_t;




 
 

  #pragma system_include






    struct __FILE
    {        
      unsigned short _Mode;
      unsigned char _Lockno;
      signed char _Handle;

       
       
       
      unsigned char *_Buf, *_Bend, *_Next;
       
       
      
  
      unsigned char *_Rend, *_Wend, *_Rback;

      
  
      _Wchart *_WRback, _WBack[2];

       
       
       
      unsigned char *_Rsave, *_WRend, *_WWend;

      _Mbstatet _Wstate;
      char *_Tmpnam;
      unsigned char _Back[1], _Cbuf;
    };

    
  

 

__intrinsic __nounwind int remove(const char *);
__intrinsic __nounwind int rename(const char *, const char *);









 



 
#pragma rtmodel="__dlib_file_descriptor","1"

                 

  typedef _Filet FILE;


      
       extern FILE __iar_Stdin;
       extern FILE __iar_Stdout;
       extern FILE __iar_Stderr;
      






                 
typedef _Fpost fpos_t;

                 
#pragma language=save
#pragma language=extended


                 
  

  __intrinsic __nounwind void clearerr(FILE *);
  __intrinsic __nounwind int fclose(FILE *);
  __intrinsic __nounwind int feof(FILE *);
  __intrinsic __nounwind int ferror(FILE *);
  __intrinsic __nounwind int fflush(FILE *);
  __intrinsic __nounwind int fgetc(FILE *);
  __intrinsic __nounwind int fgetpos(FILE *, fpos_t *);
  __intrinsic __nounwind char * fgets(char *, int, FILE *);
  __intrinsic __nounwind FILE * fopen(const char *, const char *);
  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int fprintf(FILE *, const char *, 
                                      ...);
  __intrinsic __nounwind int fputc(int, FILE *);
  __intrinsic __nounwind int fputs(const char *, FILE *);
  __intrinsic __nounwind size_t fread(void *, size_t, size_t, FILE *);
  __intrinsic __nounwind FILE * freopen(const char *, const char *,
                              FILE *);
  _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown") __intrinsic __nounwind int fscanf(FILE *, const char *, 
                                    ...);
  __intrinsic __nounwind int fseek(FILE *, long, int);
  __intrinsic __nounwind int fsetpos(FILE *, const fpos_t *);
  __intrinsic __nounwind long ftell(FILE *);
  __intrinsic __nounwind size_t fwrite(const void *, size_t, size_t, 
                             FILE *);

  __intrinsic __nounwind void rewind(FILE *);
  __intrinsic __nounwind void setbuf(FILE *, char *);
  __intrinsic __nounwind int setvbuf(FILE *, char *, int, size_t);
  __intrinsic __nounwind FILE * tmpfile(void);
  __intrinsic __nounwind int ungetc(int, FILE *);
  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vfprintf(FILE *, 
                                       const char *, __Va_list);
    _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int vfscanf(FILE *, const char *,
                                        __Va_list);

    __intrinsic __nounwind FILE * fdopen(signed char, const char *);
    __intrinsic __nounwind signed char fileno(FILE *);
    __intrinsic __nounwind int getw(FILE *);
    __intrinsic __nounwind int putw(int, FILE *);

  __intrinsic __nounwind int getc(FILE *);
  __intrinsic __nounwind int putc(int, FILE *);
  


              
_Pragma("function_effects = no_read(1), always_returns")    __intrinsic __nounwind char * __gets(char *, int);
_Pragma("function_effects = no_read(1), always_returns")    __intrinsic __nounwind char * gets(char *);
_Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind void perror(const char *);
_Pragma("function_effects = no_write(1), always_returns")    _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int printf(const char *, ...);
_Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind int puts(const char *);
_Pragma("function_effects = no_write(1), always_returns")    _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int scanf(const char *, ...);
_Pragma("function_effects = no_read(1), no_write(2), always_returns") _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int sprintf(char *, 
                                                 const char *, ...);
_Pragma("function_effects = no_write(1,2), always_returns") _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int sscanf(const char *, 
                                                const char *, ...);
             __intrinsic __nounwind char * tmpnam(char *);
              
             __intrinsic __nounwind int __ungetchar(int);
_Pragma("function_effects = no_write(1), always_returns")    _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vprintf(const char *,
                                                 __Va_list);
  _Pragma("function_effects = no_write(1), always_returns")    _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int vscanf(const char *, 
                                                  __Va_list);
  _Pragma("function_effects = no_write(1,2), always_returns") _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown")  __intrinsic __nounwind int vsscanf(const char *, 
                                                   const char *, 
                                                   __Va_list);
_Pragma("function_effects = no_read(1), no_write(2), always_returns")  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vsprintf(char *, 
                                                   const char *,
                                                   __Va_list);
               
_Pragma("function_effects = no_write(1), always_returns")      __intrinsic __nounwind size_t __write_array(const void *, size_t, size_t);
  _Pragma("function_effects = no_read(1), no_write(3), always_returns") _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int snprintf(char *, size_t, 
                                                    const char *, ...);
  _Pragma("function_effects = no_read(1), no_write(3), always_returns") _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vsnprintf(char *, size_t,
                                                     const char *, 
                                                     __Va_list);

              __intrinsic __nounwind int getchar(void);
              __intrinsic __nounwind int putchar(int);



#pragma language=restore

             
  #pragma inline
  int (getc)(FILE *_Str)
  {
    return fgetc(_Str);
  }

  #pragma inline
  int (putc)(int _C, FILE *_Str)
  {
    return fputc(_C, _Str);
  }







 
 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 












 


  #pragma system_include


  
  

  





 


  




 


  


 

  #pragma inline=forced_no_body
  __intrinsic __nounwind void * memcpy(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memcpy(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  __intrinsic __nounwind void * memmove(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memmove(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  __intrinsic __nounwind void * memset(void * _D, int _C, size_t _N)
  {
    __aeabi_memset(_D, _N, _C);
    return _D;
  }

  
  




                 

                 

_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind int        memcmp(const void *, const void *,
                                                size_t);
_Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind void *     memcpy(void *, 
                                                const void *, size_t);
_Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind void *     memmove(void *, const void *, size_t);
_Pragma("function_effects = no_state, no_read(1), returns 1, always_returns")    __intrinsic __nounwind void *     memset(void *, int, size_t);
_Pragma("function_effects = no_state, no_write(2), returns 1, always_returns")    __intrinsic __nounwind char *     strcat(char *, 
                                                const char *);
_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind int        strcmp(const char *, const char *);
_Pragma("function_effects = no_write(1,2), always_returns")     __intrinsic __nounwind int        strcoll(const char *, const char *);
_Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind char *     strcpy(char *, 
                                                const char *);
_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind size_t     strcspn(const char *, const char *);
                 __intrinsic __nounwind char *     strerror(int);
_Pragma("function_effects = no_state, no_write(1), always_returns")      __intrinsic __nounwind size_t     strlen(const char *);
_Pragma("function_effects = no_state, no_write(2), returns 1, always_returns")    __intrinsic __nounwind char *     strncat(char *, 
                                                 const char *, size_t);
_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind int        strncmp(const char *, const char *, 
                                                 size_t);
_Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind char *     strncpy(char *, 
                                                 const char *, size_t);
_Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind size_t     strspn(const char *, const char *);
_Pragma("function_effects = no_write(2), always_returns")        __intrinsic __nounwind char *     strtok(char *, 
                                                const char *);
_Pragma("function_effects = no_write(2), always_returns")        __intrinsic __nounwind size_t     strxfrm(char *, 
                                                 const char *, size_t);

  _Pragma("function_effects = no_write(1), always_returns")      __intrinsic __nounwind char *   strdup(const char *);
  _Pragma("function_effects = no_write(1,2), always_returns")   __intrinsic __nounwind int      strcasecmp(const char *, const char *);
  _Pragma("function_effects = no_write(1,2), always_returns")   __intrinsic __nounwind int      strncasecmp(const char *, const char *, 
                                                   size_t);
  _Pragma("function_effects = no_state, no_write(2), always_returns")    __intrinsic __nounwind char *   strtok_r(char *, const char *, char **);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind size_t   strnlen(char const *, size_t);



  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind void *memchr(const void *_S, int _C, size_t _N);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *strchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *strpbrk(const char *_S, const char *_P);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *strrchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *strstr(const char *_S, const char *_P);


                 

                 

_Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind void *__iar_Memchr(const void *, int, size_t);
_Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *__iar_Strchr(const char *, int);
               __intrinsic __nounwind char *__iar_Strerror(int, char *);
_Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *__iar_Strpbrk(const char *, const char *);
_Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *__iar_Strrchr(const char *, int);
_Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *__iar_Strstr(const char *, const char *);


                 
                 
    #pragma inline
    void *memchr(const void *_S, int _C, size_t _N)
    {
      return (__iar_Memchr(_S, _C, _N));
    }

    #pragma inline
    char *strchr(const char *_S, int _C)
    {
      return (__iar_Strchr(_S, _C));
    }

    #pragma inline
    char *strpbrk(const char *_S, const char *_P)
    {
      return (__iar_Strpbrk(_S, _P));
    }

    #pragma inline
    char *strrchr(const char *_S, int _C)
    {
      return (__iar_Strrchr(_S, _C));
    }

    #pragma inline
    char *strstr(const char *_S, const char *_P)
    {
      return (__iar_Strstr(_S, _P));
    }

  #pragma inline
  char *strerror(int _Err)
  {
    return (__iar_Strerror(_Err, 0));
  }









 
 
 


  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 




 
#pragma rtmodel="__dlib_full_locale_support",   "1"




extern int __aeabi_MB_CUR_MAX(void);





                 



                 
  typedef _Wchart wchar_t;

typedef struct
{        
  int quot;
  int rem;
} div_t;

typedef struct
{        
  long quot;
  long rem;
} ldiv_t;

    #pragma language=save
    #pragma language=extended
    typedef struct
    {      
      _Longlong quot;
      _Longlong rem;
    } lldiv_t;
    #pragma language=restore

                 
  
__intrinsic __nounwind int atexit(void (*)(void));
  __intrinsic __noreturn __nounwind void _Exit(int) ;
__intrinsic __noreturn __nounwind void exit(int) ;
__intrinsic __nounwind char * getenv(const char *);
__intrinsic __nounwind int system(const char *);



             __intrinsic __noreturn __nounwind void abort(void) ;
_Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind int abs(int);
             __intrinsic __nounwind void * calloc(size_t, size_t);
_Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind div_t div(int, int);
             __intrinsic __nounwind void free(void *);
_Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind long labs(long);
_Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind ldiv_t ldiv(long, long);
    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind long long llabs(long long);
    _Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind lldiv_t lldiv(long long, long long);
    #pragma language=restore
             __intrinsic __nounwind void * malloc(size_t);
_Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind int mblen(const char *, size_t);
_Pragma("function_effects = no_read(1), no_write(2), always_returns") __intrinsic __nounwind size_t mbstowcs(wchar_t *, 
                                          const char *, size_t);
_Pragma("function_effects = no_read(1), no_write(2), always_returns") __intrinsic __nounwind int mbtowc(wchar_t *, const char *, 
                                     size_t);
             __intrinsic __nounwind int rand(void);
             __intrinsic __nounwind void srand(unsigned int);
             __intrinsic __nounwind void * realloc(void *, size_t);
_Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind long strtol(const char *, 
                                      char **, int);
_Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind unsigned long strtoul(const char *, char **, int);
_Pragma("function_effects = no_read(1), no_write(2), always_returns") __intrinsic __nounwind size_t wcstombs(char *, 
                                          const wchar_t *, size_t);
_Pragma("function_effects = no_read(1), always_returns")    __intrinsic __nounwind int wctomb(char *, wchar_t);
    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind long long strtoll(const char *, char **, int);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind unsigned long long strtoull(const char *, 
                                                          char **, int);
    #pragma language=restore




    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind unsigned long __iar_Stoul(const char *, char **, 
                                                        int);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind float         __iar_Stof(const char *, char **, long);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind double        __iar_Stod(const char *, char **, long);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind long double   __iar_Stold(const char *, char **, 
                                                          long);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind long          __iar_Stolx(const char *, char **, int, 
                                                        int *);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind unsigned long __iar_Stoulx(const char *, char **,
                                                         int, int *);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind float         __iar_Stofx(const char *, char **, 
                                                        long, int *);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind double        __iar_Stodx(const char *, char **, 
                                                        long, int *);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind long double   __iar_Stoldx(const char *, char **, 
                                                         long, int *);
      #pragma language=save
      #pragma language=extended
      _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind _Longlong   __iar_Stoll(const char *, char **, 
                                                        int);
      _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind _ULonglong   __iar_Stoull(const char *, char **, 
                                                          int);
      _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind _Longlong    __iar_Stollx(const char *, char **, 
                                                          int, int *);
      _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind _ULonglong   __iar_Stoullx(const char *, char **, 
                                                           int, int *);
      #pragma language=restore





typedef int _Cmpfun(const void *, const void *);

_Pragma("function_effects = no_write(1,2), always_returns") __intrinsic void * bsearch(const void *, 
                                                   const void *, size_t,
                                                   size_t, _Cmpfun *);
             __intrinsic void qsort(void *, size_t, size_t, 
                                               _Cmpfun *);
             __intrinsic void __qsortbbl(void *, size_t, size_t, 
                                                    _Cmpfun *);
_Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind double atof(const char *);
_Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind int atoi(const char *);
_Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind long atol(const char *);
    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_write(1), always_returns") __intrinsic __nounwind long long atoll(const char *);
    #pragma language=restore
  _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind float strtof(const char *, 
                                         char **);
  _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind long double strtold(const char *, char **);
_Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind double strtod(const char *, 
                                        char **);
                                        
                                        
               __intrinsic __nounwind size_t __iar_Mbcurmax(void);

  _Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind int __iar_DLib_library_version(void);
  




  
  typedef void _Atexfun(void);
  

                 
    #pragma inline=no_body
    double atof(const char *_S)
    {       
      return (__iar_Stod(_S, 0, 0));
    }

    #pragma inline=no_body
    int atoi(const char *_S)
    {       
      return ((int)__iar_Stoul(_S, 0, 10));
    }

    #pragma inline=no_body
    long atol(const char *_S)
    {       
      return ((long)__iar_Stoul(_S, 0, 10));
    }

        #pragma language=save
        #pragma language=extended
        #pragma inline=no_body
        long long atoll(const char *_S)
        {       
            return ((long long)__iar_Stoull(_S, 0, 10));
        }
        #pragma language=restore

    #pragma inline=no_body
    double strtod(const char * _S, char ** _Endptr)
    {       
      return (__iar_Stod(_S, _Endptr, 0));
    }

      #pragma inline=no_body
      float strtof(const char * _S, char ** _Endptr)
      {       
        return (__iar_Stof(_S, _Endptr, 0));
      }

      #pragma inline=no_body
      long double strtold(const char * _S, char ** _Endptr)
      {       
        return (__iar_Stold(_S, _Endptr, 0));
      }

    #pragma inline=no_body
    long strtol(const char * _S, char ** _Endptr, 
                int _Base)
    {       
      return (__iar_Stolx(_S, _Endptr, _Base, 0));
    }

    #pragma inline=no_body
    unsigned long strtoul(const char * _S, char ** _Endptr, 
                          int _Base)
    {       
      return (__iar_Stoul(_S, _Endptr, _Base));
    }

        #pragma language=save
        #pragma language=extended
        #pragma inline=no_body
        long long strtoll(const char * _S, char ** _Endptr,
                          int _Base)
        {       
            return (__iar_Stoll(_S, _Endptr, _Base));
        }

        #pragma inline=no_body
        unsigned long long strtoull(const char * _S, 
                                    char ** _Endptr, int _Base)
        {       
            return (__iar_Stoull(_S, _Endptr, _Base));
        }
        #pragma language=restore


  #pragma inline=no_body
  int abs(int i)
  {       
    return (i < 0 ? -i : i);
  }

  #pragma inline=no_body
  long labs(long i)
  {       
    return (i < 0 ? -i : i);
  }

      #pragma language=save
      #pragma language=extended
      #pragma inline=no_body
      long long llabs(long long i)
      {       
        return (i < 0 ? -i : i);
      }
      #pragma language=restore








 








 


 
 

 

  #pragma system_include






 















 





  #pragma system_include



 


 


#pragma language=save
#pragma language=extended

__intrinsic __nounwind void    __no_operation(void);

__intrinsic __nounwind void    __disable_interrupt(void);
__intrinsic __nounwind void    __enable_interrupt(void);

typedef unsigned long __istate_t;

__intrinsic __nounwind __istate_t __get_interrupt_state(void);
__intrinsic __nounwind void __set_interrupt_state(__istate_t);


 
__intrinsic __nounwind unsigned long __get_PSR( void );
__intrinsic __nounwind unsigned long __get_IPSR( void );
_Pragma("function_effects = hidden_state, always_returns") __intrinsic __nounwind unsigned long __get_MSP( void );
__intrinsic __nounwind void          __set_MSP( unsigned long );
_Pragma("function_effects = hidden_state, always_returns") __intrinsic __nounwind unsigned long __get_PSP( void );
__intrinsic __nounwind void          __set_PSP( unsigned long );
_Pragma("function_effects = hidden_state, always_returns") __intrinsic __nounwind unsigned long __get_PRIMASK( void );
__intrinsic __nounwind void          __set_PRIMASK( unsigned long );
_Pragma("function_effects = hidden_state, always_returns") __intrinsic __nounwind unsigned long __get_CONTROL( void );
__intrinsic __nounwind void          __set_CONTROL( unsigned long );


__intrinsic __nounwind void __disable_fiq(void);
__intrinsic __nounwind void __enable_fiq(void);


 

_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind unsigned long __SWP( unsigned long, volatile unsigned long * );
_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind unsigned char __SWPB( unsigned char, volatile unsigned char * );

typedef unsigned long __ul;


 
__intrinsic __nounwind void          __MCR( unsigned __constrange(0,15) coproc, unsigned __constrange(0,8) opcode_1, __ul src,
                                 unsigned __constrange(0,15) CRn, unsigned __constrange(0,15) CRm, unsigned __constrange(0,8) opcode_2 );
__intrinsic __nounwind unsigned long __MRC( unsigned __constrange(0,15) coproc, unsigned __constrange(0,8) opcode_1,
                                 unsigned __constrange(0,15) CRn, unsigned __constrange(0,15) CRm, unsigned __constrange(0,8) opcode_2 );
__intrinsic __nounwind void          __MCR2( unsigned __constrange(0,15) coproc, unsigned __constrange(0,8) opcode_1, __ul src,
                                  unsigned __constrange(0,15) CRn, unsigned __constrange(0,15) CRm, unsigned __constrange(0,8) opcode_2 );
__intrinsic __nounwind unsigned long __MRC2( unsigned __constrange(0,15) coproc, unsigned __constrange(0,8) opcode_1,
                                  unsigned __constrange(0,15) CRn, unsigned __constrange(0,15) CRm, unsigned __constrange(0,8) opcode_2 );

 
__intrinsic __nounwind void __LDC( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src);
__intrinsic __nounwind void __LDCL( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src);
__intrinsic __nounwind void __LDC2( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src);
__intrinsic __nounwind void __LDC2L( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src);

 
__intrinsic __nounwind void __STC( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst);
__intrinsic __nounwind void __STCL( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst);
__intrinsic __nounwind void __STC2( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst);
__intrinsic __nounwind void __STC2L( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst);

 
__intrinsic __nounwind void __LDC_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src,
                              unsigned __constrange(0,255) option);

__intrinsic __nounwind void __LDCL_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src,
                               unsigned __constrange(0,255) option);

__intrinsic __nounwind void __LDC2_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src,
                               unsigned __constrange(0,255) option);

__intrinsic __nounwind void __LDC2L_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src,
                                unsigned __constrange(0,255) option);

 
__intrinsic __nounwind void __STC_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst,
                              unsigned __constrange(0,255) option);

__intrinsic __nounwind void __STCL_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst,
                               unsigned __constrange(0,255) option);

__intrinsic __nounwind void __STC2_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst,
                               unsigned __constrange(0,255) option);

__intrinsic __nounwind void __STC2L_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst,
                                unsigned __constrange(0,255) option);

 
__intrinsic __nounwind unsigned long __get_APSR( void );
__intrinsic __nounwind void          __set_APSR( unsigned long );

 
__intrinsic __nounwind unsigned long __get_FPSCR( void );
__intrinsic __nounwind void __set_FPSCR( unsigned long );

 
_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind unsigned char __CLZ( unsigned long );

 

_Pragma("function_effects = hidden_state, always_returns") __intrinsic __nounwind int         __QCFlag( void );
_Pragma("function_effects = hidden_state, always_returns") __intrinsic __nounwind void __reset_QC_flag( void );

_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind signed long __SMUL( signed short, signed short );

 
_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind unsigned long __REV( unsigned long );
_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind signed long __REVSH( short );

_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind unsigned long __REV16( unsigned long );
_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind unsigned long __RBIT( unsigned long );

_Pragma("function_effects = no_state, no_write(1), always_returns") __intrinsic __nounwind unsigned char  __LDREXB( volatile unsigned char const * );
_Pragma("function_effects = no_state, no_write(1), always_returns") __intrinsic __nounwind unsigned short __LDREXH( volatile unsigned short const * );
_Pragma("function_effects = no_state, no_write(1), always_returns") __intrinsic __nounwind unsigned long  __LDREX ( volatile unsigned long const * );
_Pragma("function_effects = no_state, no_write(1), always_returns") __intrinsic __nounwind unsigned long long __LDREXD( volatile unsigned long long const * );

_Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind unsigned long  __STREXB( unsigned char, volatile unsigned char * );
_Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind unsigned long  __STREXH( unsigned short, volatile unsigned short * );
_Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind unsigned long  __STREX ( unsigned long, volatile unsigned long * );
_Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind unsigned long  __STREXD( unsigned long long, volatile unsigned long long * );

__intrinsic __nounwind void __CLREX( void );

__intrinsic __nounwind void __SEV( void );
__intrinsic __nounwind void __WFE( void );
__intrinsic __nounwind void __WFI( void );
__intrinsic __nounwind void __YIELD( void );

__intrinsic __nounwind void __PLI( volatile void const * );
__intrinsic __nounwind void __PLD( volatile void const * );
__intrinsic __nounwind void __PLDW( volatile void const * );

_Pragma("function_effects = hidden_state, always_returns") __intrinsic __nounwind   signed long __SSAT     (unsigned long val,
                                      unsigned int __constrange( 1, 32 ) sat );
_Pragma("function_effects = hidden_state, always_returns") __intrinsic __nounwind unsigned long __USAT     (unsigned long val,
                                      unsigned int __constrange( 0, 31 ) sat );



 
__intrinsic __nounwind void __DMB(void);
__intrinsic __nounwind void __DSB(void);
__intrinsic __nounwind void __ISB(void);

 
__intrinsic __nounwind unsigned long __TT(unsigned long);
__intrinsic __nounwind unsigned long __TTT(unsigned long);
__intrinsic __nounwind unsigned long __TTA(unsigned long);
__intrinsic __nounwind unsigned long __TTAT(unsigned long);


__intrinsic __nounwind unsigned long __get_LR(void);
__intrinsic __nounwind void __set_LR(unsigned long);

__intrinsic __nounwind unsigned long __get_SP(void);
__intrinsic __nounwind void __set_SP(unsigned long);

#pragma language=restore

















 
















 



void write_vtor (int);                                              





void vcan_cpy( uint8 *dst, uint8 *src, uint32 count);

void soft_delay_ms(uint32 ms);
void soft_delay_us(uint32 us);





 







 

























 


#pragma system_include   



    










 


    

 
    

 

     





    
 



 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 






 
  typedef signed char   int8_t;
  typedef unsigned char uint8_t;

  typedef signed short int   int16_t;
  typedef unsigned short int uint16_t;

  typedef signed int   int32_t;
  typedef unsigned int uint32_t;

  #pragma language=save
  #pragma language=extended
  typedef signed long long int   int64_t;
  typedef unsigned long long int uint64_t;
  #pragma language=restore


 
typedef signed char   int_least8_t;
typedef unsigned char uint_least8_t;

typedef signed short int   int_least16_t;
typedef unsigned short int uint_least16_t;

typedef signed int   int_least32_t;
typedef unsigned int uint_least32_t;

 
  #pragma language=save
  #pragma language=extended
  typedef signed long long int int_least64_t;
  #pragma language=restore
  #pragma language=save
  #pragma language=extended
  typedef unsigned long long int uint_least64_t;
  #pragma language=restore



 
typedef signed int   int_fast8_t;
typedef unsigned int uint_fast8_t;

typedef signed int   int_fast16_t;
typedef unsigned int uint_fast16_t;

typedef signed int   int_fast32_t;
typedef unsigned int uint_fast32_t;

  #pragma language=save
  #pragma language=extended
  typedef signed long long int int_fast64_t;
  #pragma language=restore
  #pragma language=save
  #pragma language=extended
  typedef unsigned long long int uint_fast64_t;
  #pragma language=restore

 
#pragma language=save
#pragma language=extended
typedef signed long long int   intmax_t;
typedef unsigned long long int uintmax_t;
#pragma language=restore


 
typedef signed long int   intptr_t;
typedef unsigned long int uintptr_t;

 
typedef int __data_intptr_t; typedef unsigned int __data_uintptr_t;

 

























 














 
 







 

























 
































































 








 




 

 

 

 
 





 


 
 




 




 

 


   




 




 


 







 

























 


#pragma system_include   




     

     
    





 

     



    







 
    

 

    



 

    
 
    typedef union
    {
        struct
        {
            uint32_t _reserved0: 27;              
            uint32_t Q: 1;                        
            uint32_t V: 1;                        
            uint32_t C: 1;                        
            uint32_t Z: 1;                        
            uint32_t N: 1;                        
        } b;                                    
        uint32_t w;                             
    } APSR_Type;


    
 
    typedef union
    {
        struct
        {
            uint32_t ISR: 9;                      
            uint32_t _reserved0: 23;              
        } b;                                    
        uint32_t w;                             
    } IPSR_Type;


    
 
    typedef union
    {
        struct
        {
            uint32_t ISR: 9;                      
            uint32_t _reserved0: 15;              
            uint32_t T: 1;                        
            uint32_t IT: 2;                       
            uint32_t Q: 1;                        
            uint32_t V: 1;                        
            uint32_t C: 1;                        
            uint32_t Z: 1;                        
            uint32_t N: 1;                        
        } b;                                    
        uint32_t w;                             
    } xPSR_Type;


    
 
    typedef union
    {
        struct
        {
            uint32_t nPRIV: 1;                    
            uint32_t SPSEL: 1;                    
            uint32_t FPCA: 1;                     
            uint32_t _reserved0: 29;              
        } b;                                    
        uint32_t w;                             
    } CONTROL_Type;

     


    



 

    
 
    typedef struct
    {
        volatile uint32_t ISER[1];                  
        uint32_t RESERVED0[31];
        volatile uint32_t ICER[1];                  
        uint32_t RSERVED1[31];
        volatile uint32_t ISPR[1];                  
        uint32_t RESERVED2[31];
        volatile uint32_t ICPR[1];                  
        uint32_t RESERVED3[31];
        uint32_t RESERVED4[64];
        volatile uint32_t IP[8];                    
    }  NVIC_Type;

     


    



 

    
 
    typedef struct
    {
        volatile const  uint32_t CPUID;                    
        volatile uint32_t ICSR;                     
        volatile uint32_t VTOR;                     
        volatile uint32_t AIRCR;                    
        volatile uint32_t SCR;                      
        volatile uint32_t CCR;                      
        uint32_t RESERVED1;
        volatile uint32_t SHP[2];                   
        volatile uint32_t SHCSR;                    
    } SCB_Type;

     





     









     

     





     



     


     

     


    



 

    
 
    typedef struct
    {
        volatile uint32_t CTRL;                     
        volatile uint32_t LOAD;                     
        volatile uint32_t VAL;                      
        volatile const  uint32_t CALIB;                    
    } SysTick_Type;

     




     

     

     



     



    





 
     


    



 

     



     



    





 
    
 



     
    



 

     
     


    




 
    static inline void NVIC_EnableIRQ(IRQn_Type IRQn)
    {
        ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0] = (1 << ((uint32_t)(IRQn) & 0x1F));
    }


    




 
    static inline void NVIC_DisableIRQ(IRQn_Type IRQn)
    {
        ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[0] = (1 << ((uint32_t)(IRQn) & 0x1F));
    }


    








 
    static inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
    {
        return((uint32_t) ((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0] & (1 << ((uint32_t)(IRQn) & 0x1F))) ? 1 : 0));
    }


    




 
    static inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
    {
        ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0] = (1 << ((uint32_t)(IRQn) & 0x1F));
    }


    




 
    static inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
    {
        ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[0] = (1 << ((uint32_t)(IRQn) & 0x1F));  
    }


    







 
    static inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
    {
        if(IRQn < 0)
        {
            ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( ((((uint32_t)(IRQn) & 0x0F)-8) >> 2) )] = (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( ((((uint32_t)(IRQn) & 0x0F)-8) >> 2) )] & ~(0xFF << ( (((uint32_t)(IRQn) ) & 0x03) * 8 ))) |
                                       (((priority << (8 - 2)) & 0xFF) << ( (((uint32_t)(IRQn) ) & 0x03) * 8 ));
        }
        else
        {
            ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( ((uint32_t)(IRQn) >> 2) )] = (((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( ((uint32_t)(IRQn) >> 2) )] & ~(0xFF << ( (((uint32_t)(IRQn) ) & 0x03) * 8 ))) |
                                      (((priority << (8 - 2)) & 0xFF) << ( (((uint32_t)(IRQn) ) & 0x03) * 8 ));
        }
    }


    









 
    static inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
    {

        if(IRQn < 0)
        {
            return((uint32_t)(((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( ((((uint32_t)(IRQn) & 0x0F)-8) >> 2) )] >> ( (((uint32_t)(IRQn) ) & 0x03) * 8 ) ) & 0xFF) >> (8 - 2)));
        }  
        else
        {
            return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[ ( ((uint32_t)(IRQn) >> 2) )] >> ( (((uint32_t)(IRQn) ) & 0x03) * 8 ) ) & 0xFF) >> (8 - 2)));
        }  
    }


    


 
    static inline void NVIC_SystemReset(void)
    {
        __DSB();                                                     
 
        ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = ((0x5FA << 16)      |
                       (1UL << 2));
        __DSB();                                                      
        while(1);                                                     
    }

     



     
    



 


    













 
    static inline uint32_t SysTick_Config(uint32_t ticks)
    {
        if ((ticks - 1) > (0xFFFFFFUL << 0))  return (1);       

        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = ticks - 1;                                   
        NVIC_SetPriority (SysTick_IRQn, (1 << 2) - 1);  
        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0;                                           
        ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2) |
                         (1UL << 1)   |
                         (1UL << 0);                     
        return (0);                                                   
    }


     




















 


extern int core_clk_khz;
extern int core_clk_mhz;
extern int bus_clk_khz;
extern int timer_clk_khz;

void start(void);           
void sysinit (void);        

void common_startup(void);  




   




 




 




 

#pragma language=extended



 




 

 
typedef struct
{
    volatile uint8_t CS;                                  
    volatile uint8_t C0;                                  
    volatile uint8_t C1;                                  
    volatile uint8_t C2;                                  
} ACMP_Type, *ACMP_MemMapPtr;



 




 


 



   




 




 

 
 
 
 



   


 
 
 
 
 
 
 



 




 


 
 
 



   




   




 




 

 
typedef struct
{
    volatile uint32_t SC1;                                
    volatile uint32_t SC2;                                
    volatile uint32_t SC3;                                
    volatile uint32_t SC4;                                
    volatile const  uint32_t R;                                  
    volatile uint32_t CV;                                 
    volatile uint32_t APCTL1;                             
    volatile uint32_t SC5;                                
} ADC_Type, *ADC_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    union                                             
    {
        struct                                            
        {
            volatile uint16_t DATAL;                              
            volatile uint16_t DATAH;                              
        } ACCESS16BIT;
        volatile uint32_t DATA;                               
        struct                                            
        {
            volatile uint8_t DATALL;                              
            volatile uint8_t DATALU;                              
            volatile uint8_t DATAHL;                              
            volatile uint8_t DATAHU;                              
        } ACCESS8BIT;
    };
    union                                             
    {
        struct                                            
        {
            volatile uint16_t GPOLYL;                             
            volatile uint16_t GPOLYH;                             
        } GPOLY_ACCESS16BIT;
        volatile uint32_t GPOLY;                              
        struct                                            
        {
            volatile uint8_t GPOLYLL;                             
            volatile uint8_t GPOLYLU;                             
            volatile uint8_t GPOLYHL;                             
            volatile uint8_t GPOLYHU;                             
        } GPOLY_ACCESS8BIT;
    };
    union                                             
    {
        volatile uint32_t CTRL;                               
        struct                                            
        {
            uint8_t RESERVED_0[3];
            volatile uint8_t CTRLHU;                              
        } CTRL_ACCESS8BIT;
    };
} CRC_Type, *CRC_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint32_t PDOR;                               
    volatile  uint32_t PSOR;                               
    volatile  uint32_t PCOR;                               
    volatile  uint32_t PTOR;                               
    volatile const  uint32_t PDIR;                               
    volatile uint32_t PDDR;                               
    volatile uint32_t PIDR;                               
} FGPIO_Type, *FGPIO_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 



   


 
 
 
 
 
 
 
 
 



 




 


 
 
 
 



   




   




 




 

 
typedef struct
{
    volatile uint32_t SC;                                 
    volatile uint32_t CNT;                                
    volatile uint32_t MOD;                                
    struct                                            
    {
        volatile uint32_t CnSC;                               
        volatile uint32_t CnV;                                
    } CONTROLS[6];
    uint8_t RESERVED_0[16];
    volatile uint32_t CNTIN;                              
    volatile uint32_t STATUS;                             
    volatile uint32_t MODE;                               
    volatile uint32_t SYNC;                               
    volatile uint32_t OUTINIT;                            
    volatile uint32_t OUTMASK;                            
    volatile uint32_t COMBINE;                            
    volatile uint32_t DEADTIME;                           
    volatile uint32_t EXTTRIG;                            
    volatile uint32_t POL;                                
    volatile uint32_t FMS;                                
    volatile uint32_t FILTER;                             
    volatile uint32_t FLTCTRL;                            
    uint8_t RESERVED_1[4];
    volatile uint32_t CONF;                               
    volatile uint32_t FLTPOL;                             
    volatile uint32_t SYNCONF;                            
    volatile uint32_t INVCTRL;                            
    volatile uint32_t SWOCTRL;                            
    volatile uint32_t PWMLOAD;                            
} FTM_Type, *FTM_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



   


 
 
 
 
 
 
 
 
 



 




 


 
 
 
 

 



   




   




 




 

 
typedef struct
{
    uint8_t RESERVED_0[1];
    volatile uint8_t FCCOBIX;                             
    volatile const  uint8_t FSEC;                                
    volatile uint8_t FCLKDIV;                             
    uint8_t RESERVED_1[1];
    volatile uint8_t FSTAT;                               
    uint8_t RESERVED_2[1];
    volatile uint8_t FCNFG;                               
    volatile uint8_t FCCOBLO;                             
    volatile uint8_t FCCOBHI;                             
    uint8_t RESERVED_3[1];
    volatile uint8_t FPROT;                               
    uint8_t RESERVED_4[3];
    volatile const  uint8_t FOPT;                                
} FTMRE_Type, *FTMRE_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint32_t PDOR;                               
    volatile  uint32_t PSOR;                               
    volatile  uint32_t PCOR;                               
    volatile  uint32_t PTOR;                               
    volatile const  uint32_t PDIR;                               
    volatile uint32_t PDDR;                               
    volatile uint32_t PIDR;                               
} GPIO_Type, *GPIO_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 



   


 
 
 
 
 
 
 
 
 



 




 


 
 
 
 



   




   




 




 

 
typedef struct
{
    volatile uint8_t A1;                                  
    volatile uint8_t F;                                   
    volatile uint8_t C1;                                  
    volatile uint8_t S1;                                  
    volatile uint8_t D;                                   
    volatile uint8_t C2;                                  
    volatile uint8_t FLT;                                 
    volatile uint8_t RA;                                  
    volatile uint8_t SMB;                                 
    volatile uint8_t A2;                                  
    volatile uint8_t SLTH;                                
    volatile uint8_t SLTL;                                
} I2C_Type, *I2C_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 
 
 
 
 



   


 
 
 
 
 
 
 



 




 


 
 
 



   




   




 




 

 
typedef struct
{
    volatile uint8_t C1;                                  
    volatile uint8_t C2;                                  
    volatile uint8_t C3;                                  
    volatile uint8_t C4;                                  
    volatile uint8_t S;                                   
} ICS_Type, *ICS_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint8_t SC;                                  
} IRQ_Type, *IRQ_MemMapPtr;



 




 


 



   




 




 

 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint32_t PE;                                 
    volatile uint32_t ES;                                 
    volatile uint32_t SC;                                 
    volatile const  uint32_t SP;                                 
} KBI_Type, *KBI_MemMapPtr;



 




 


 



   




 




 

 
 
 
 



   


 
 
 
 
 
 
 



 




 


 
 
 



   




   




 




 

 
typedef struct
{
    uint8_t RESERVED_0[8];
    volatile const  uint16_t PLASC;                              
    volatile const  uint16_t PLAMC;                              
    volatile uint32_t PLACR;                              
} MCM_Type, *MCM_MemMapPtr;



 




 


 



   




 




 

 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint8_t CANCTL0;                             
    volatile uint8_t CANCTL1;                             
    volatile uint8_t CANBTR0;                             
    volatile uint8_t CANBTR1;                             
    volatile uint8_t CANRFLG;                             
    volatile uint8_t CANRIER;                             
    volatile uint8_t CANTFLG;                             
    volatile uint8_t CANTIER;                             
    volatile uint8_t CANTARQ;                             
    volatile const  uint8_t CANTAAK;                             
    volatile uint8_t CANTBSEL;                            
    volatile uint8_t CANIDAC;                             
    uint8_t RESERVED_0[1];
    volatile uint8_t CANMISC;                             
    volatile const  uint8_t CANRXERR;                            
    volatile const  uint8_t CANTXERR;                            
    volatile uint8_t CANIDAR_BANK_1[4];                   
    volatile uint8_t CANIDMR_BANK_1[4];                   
    volatile uint8_t CANIDAR_BANK_2[4];                   
    volatile uint8_t CANIDMR_BANK_2[4];                   
    union                                             
    {
        volatile uint8_t REIDR0;                              
        volatile uint8_t RSIDR0;                              
    };
    union                                             
    {
        volatile uint8_t REIDR1;                              
        volatile uint8_t RSIDR1;                              
    };
    volatile uint8_t REIDR2;                              
    volatile uint8_t REIDR3;                              
    volatile uint8_t REDSR[8];                            
    volatile uint8_t RDLR;                                
    uint8_t RESERVED_1[1];
    volatile uint8_t RTSRH;                               
    volatile uint8_t RTSRL;                               
    union                                             
    {
        volatile uint8_t TEIDR0;                              
        volatile uint8_t TSIDR0;                              
    };
    union                                             
    {
        volatile uint8_t TEIDR1;                              
        volatile uint8_t TSIDR1;                              
    };
    volatile uint8_t TEIDR2;                              
    volatile uint8_t TEIDR3;                              
    volatile uint8_t TEDSR[8];                            
    volatile uint8_t TDLR;                                
    volatile uint8_t TBPR;                                
    volatile uint8_t TTSRH;                               
    volatile uint8_t TTSRL;                               
} MSCAN_Type, *MSCAN_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



   


 
 
 
 
 



 




 


 
 

 



   




   




 




 

 
typedef struct
{
    volatile const  uint8_t BACKKEY0;                            
    volatile const  uint8_t BACKKEY1;                            
    volatile const  uint8_t BACKKEY2;                            
    volatile const  uint8_t BACKKEY3;                            
    volatile const  uint8_t BACKKEY4;                            
    volatile const  uint8_t BACKKEY5;                            
    volatile const  uint8_t BACKKEY6;                            
    volatile const  uint8_t BACKKEY7;                            
    uint8_t RESERVED_0[5];
    volatile const  uint8_t FPROT;                               
    volatile const  uint8_t FSEC;                                
    volatile const  uint8_t FOPT;                                
} NV_Type, *NV_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint8_t CR;                                  
} OSC_Type, *OSC_MemMapPtr;



 




 


 



   




 




 

 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint32_t MCR;                                
    uint8_t RESERVED_0[252];
    struct                                            
    {
        volatile uint32_t LDVAL;                              
        volatile const  uint32_t CVAL;                               
        volatile uint32_t TCTRL;                              
        volatile uint32_t TFLG;                               
    } CHANNEL[2];
} PIT_Type, *PIT_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 



   


 
 
 
 
 



 




 


 
 

 



   




   




 




 

 
typedef struct
{
    volatile uint8_t SPMSC1;                              
    volatile uint8_t SPMSC2;                              
} PMC_Type, *PMC_MemMapPtr;



 




 


 



   




 




 

 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint32_t IOFLT0;                             
    volatile uint32_t IOFLT1;                             
    volatile uint32_t PUE0;                               
    volatile uint32_t PUE1;                               
    volatile uint32_t PUE2;                               
    volatile uint32_t HDRVE;                              
} PORT_Type, *PORT_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint32_t R1;                                 
    volatile const  uint32_t R2;                                 
} PWT_Type, *PWT_MemMapPtr;



 




 


 



   




 




 

 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile const  uint32_t ENTRY[1];                           
    volatile const  uint32_t TABLEMARK;                          
    uint8_t RESERVED_0[4036];
    volatile const  uint32_t SYSACCESS;                          
    volatile const  uint32_t PERIPHID4;                          
    volatile const  uint32_t PERIPHID5;                          
    volatile const  uint32_t PERIPHID6;                          
    volatile const  uint32_t PERIPHID7;                          
    volatile const  uint32_t PERIPHID0;                          
    volatile const  uint32_t PERIPHID1;                          
    volatile const  uint32_t PERIPHID2;                          
    volatile const  uint32_t PERIPHID3;                          
    volatile const  uint32_t COMPID[4];                          
} ROM_Type, *ROM_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 
 
 
 
 



   


 
 
 
 
 



 




 


 
 

 



   




   




 




 

 
typedef struct
{
    volatile uint32_t SC;                                 
    volatile uint32_t MOD;                                
    volatile const  uint32_t CNT;                                
} RTC_Type, *RTC_MemMapPtr;



 




 


 



   




 




 

 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile const  uint32_t SRSID;                              
    volatile uint32_t SOPT0;                              
    volatile uint32_t SOPT1;                              
    volatile uint32_t PINSEL;                             
    volatile uint32_t PINSEL1;                            
    volatile uint32_t SCGC;                               
    volatile const  uint32_t UUIDL;                              
    volatile const  uint32_t UUIDML;                             
    volatile const  uint32_t UUIDMH;                             
    volatile uint32_t CLKDIV;                             
} SIM_Type, *SIM_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 




 

 
typedef struct
{
    volatile uint8_t C1;                                  
    volatile uint8_t C2;                                  
    volatile uint8_t BR;                                  
    volatile const  uint8_t S;                                   
    uint8_t RESERVED_0[1];
    volatile uint8_t D;                                   
    uint8_t RESERVED_1[1];
    volatile uint8_t M;                                   
} SPI_Type, *SPI_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 



   


 
 
 
 
 
 
 



 




 


 
 
 



   




   




 




 

 
typedef struct
{
    volatile uint8_t BDH;                                 
    volatile uint8_t BDL;                                 
    volatile uint8_t C1;                                  
    volatile uint8_t C2;                                  
    volatile const  uint8_t S1;                                  
    volatile uint8_t S2;                                  
    volatile uint8_t C3;                                  
    volatile uint8_t D;                                   
} UART_Type, *UART_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 



   


 
 
 
 
 
 
 
 
 



 




 


 
 
 
 



   




   




 




 

 
typedef struct
{
    volatile uint8_t CS1;                                 
    volatile uint8_t CS2;                                 
    union                                             
    {
        volatile uint16_t CNT;                                
        struct                                            
        {
            volatile const  uint8_t CNTH;                                
            volatile const  uint8_t CNTL;                                
        } CNT8B;
    };
    union                                             
    {
        volatile uint16_t TOVAL;                              
        struct                                            
        {
            volatile uint8_t TOVALH;                              
            volatile uint8_t TOVALL;                              
        } TOVAL8B;
    };
    union                                             
    {
        volatile uint16_t WIN;                                
        struct                                            
        {
            volatile uint8_t WINH;                                
            volatile uint8_t WINL;                                
        } WIN8B;
    };
} WDOG_Type, *WDOG_MemMapPtr;



 




 


 



   




 




 

 
 
 
 
 
 
 
 
 
 
 



   


 
 
 
 
 



 




 


 
 



   




   




 

#pragma language=default



   




 




 




   



 



 



 

 










 



#pragma system_include


   

#pragma diag_suppress=Pe940
#pragma diag_suppress=Pe177






static uint32_t __get_xPSR(void)
{
  return __get_PSR();    
}







static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  return (op1 >> op2) | (op1 << ((sizeof(op1)*8)-op2));
}

#pragma diag_default=Pe940
#pragma diag_default=Pe177




   

 







 

























 
































































 








 




 

 
 

 


 



 

 


 






 







 

























 
































































 








 




 

 
 

 







































 


























































































































 




 








 









 



 






































































 



 



 



 


 






 



 

 


 




 

























 


 #pragma system_include          



 
 





 
 
 

  #pragma system_include

 
 

 

  #pragma system_include






 















 




 
 

  #pragma system_include



 
 

 

  #pragma system_include






 















 








                 



_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind short        __iar_Dtest(double);
_Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind int          __iar_Dsign(double);

  _Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind short        __iar_FDtest(float);
  _Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind int          __iar_FDsign(float);




                 
typedef union
{        
  unsigned short _Word[8 / 2];
  float _Float;
  double _Double;
  long double _Long_double;
} _Dconst;

                 
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double       __iar_Cosh(double, double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double       __iar_Erfc(double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind short        __iar_Exp(double *, double, long);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double       __iar_Log(double, int);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_Log_small(double, int);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double       __iar_Logpoly(double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind unsigned int __iar_Quad(double *);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind unsigned int __iar_QuadXp(double *);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind unsigned int __iar_Quadph(double *, double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double       __iar_Rint(double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double       __iar_Sin(double, unsigned int);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_Sin_small(double, unsigned int);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double       __iar_Sinh(double, double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double       __iar_Tgamma(double *, short *pex);

                 
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float        __iar_FCosh(float, float);
  _Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind short        __iar_FDtest(float);
  _Pragma("function_effects = no_state, always_returns") __intrinsic __nounwind int          __iar_FDsign(float);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float        __iar_FErfc(float);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind short        __iar_FExp(float *, float, long);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float        __iar_FLog(float, int);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_Log_smallf(float, int);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float        __iar_FLogpoly(float);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind unsigned int __iar_FQuad(float *);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind unsigned int __iar_FQuadXp(float *);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind unsigned int __iar_FQuadph(float *, float);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float        __iar_FRint(float);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float        __iar_FSin(float, unsigned int);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_Sin_smallf(float, unsigned int);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float        __iar_FSinh(float, float);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float        __iar_FTgamma(float *, short *pex);

                 


 extern float const __aeabi_HUGE_VALF;
 extern float const __aeabi_INFINITY;
 extern float const __aeabi_NAN;
 extern double const __aeabi_HUGE_VAL;
 extern long double const __aeabi_HUGE_VALL;

                 
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double (atan2l)(long double, long double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double (cosl)(long double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double (expl)(long double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double (ldexpl)(long double, int);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double (logl)(long double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double (powl)(long double, long double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double (sinl)(long double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double (sqrtl)(long double);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double (tanl)(long double);
                 
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float (atan2f)(float, float);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float (cosf)(float);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float (expf)(float);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float (ldexpf)(float, int);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float (logf)(float);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float (powf)(float, float);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float (sinf)(float);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float (sqrtf)(float);
_Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float (tanf)(float);









 
 
 

  #pragma system_include









 






  typedef float float_t;
  typedef double double_t;



                 
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double acos(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double asin(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double atan(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double atan2(double, double);
_Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double ceil(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double exp(double);
_Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double fabs(double);
_Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double floor(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double fmod(double, double);
_Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind double frexp(double, int *);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double ldexp(double, int);
_Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind double modf(double, double *);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double pow(double, double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double sqrt(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double tan(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double tanh(double);

_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double cos(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double cosh(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double log(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double log10(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double sin(double);
_Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double sinh(double);


                 
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double acosh(double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double asinh(double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double atanh(double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double cbrt(double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double copysign(double, double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double erf(double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double erfc(double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double expm1(double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double exp2(double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double fdim(double, double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double fma(double, double, double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double fmax(double, double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double fmin(double, double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double hypot(double, double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind int    ilogb(double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double lgamma(double);
    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind _Longlong llrint(double);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind _Longlong llround(double);
    #pragma language=restore
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double log1p(double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double log2(double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double logb(double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long   lrint(double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long   lround(double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double nan(const char *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double nearbyint(double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double nextafter(double, double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double nexttoward(double, long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double remainder(double, double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double remquo(double, double, int *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double rint(double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double round(double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double scalbn(double, int);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double scalbln(double, long);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind double tgamma(double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind double trunc(double);

                 
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float acosf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float asinf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float atanf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float atan2f(float, float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float ceilf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float expf(float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float fabsf(float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float floorf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float fmodf(float, float);
  _Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind float frexpf(float, int *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float ldexpf(float, int);
  _Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind float modff(float, float *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float powf(float, float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float sqrtf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float tanf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float tanhf(float);

  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float acoshf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float asinhf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float atanhf(float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float cbrtf(float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float copysignf(float, float);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float erff(float);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float erfcf(float);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float expm1f(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float exp2f(float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float fdimf(float, float);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float fmaf(float, float, float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float fmaxf(float, float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float fminf(float, float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float hypotf(float, float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind int   ilogbf(float);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float lgammaf(float);
    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind _Longlong llrintf(float);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind _Longlong llroundf(float);
    #pragma language=restore
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float log1pf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float log2f(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float logbf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long  lrintf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long  lroundf(float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float nanf(const char *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float nearbyintf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float nextafterf(float, float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float nexttowardf(float, long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float remainderf(float, float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float remquof(float, float, int *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float rintf(float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float roundf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float scalbnf(float, int);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float scalblnf(float, long);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float tgammaf(float);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind float truncf(float);

  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float cosf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float coshf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float logf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float log10f(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float sinf(float);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind float sinhf(float);

                 
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double acosl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double asinl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double atanl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double atan2l(long double, long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double ceill(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double expl(long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double fabsl(long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double floorl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double fmodl(long double, long double);
  _Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind long double frexpl(long double, int *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double ldexpl(long double, int);
  _Pragma("function_effects = no_state, no_read(2), always_returns") __intrinsic __nounwind long double modfl(long double, long double *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double powl(long double, long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double sqrtl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double tanl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double tanhl(long double);

  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double acoshl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double asinhl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double atanhl(long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double cbrtl(long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double copysignl(long double, long double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double erfl(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double erfcl(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double expm1l(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double exp2l(long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double fdiml(long double, long double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double fmal(long double, long double, 
                                              long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double fmaxl(long double, long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double fminl(long double, long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double hypotl(long double, long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind int         ilogbl(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double lgammal(long double);
    #pragma language=save
    #pragma language=extended
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind _Longlong llrintl(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind _Longlong llroundl(long double);
    #pragma language=restore
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double log1pl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double log2l(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double logbl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long        lrintl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long lroundl(long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double nanl(const char *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double nearbyintl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double nextafterl(long double, long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double nexttowardl(long double, long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double remainderl(long double, long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double remquol(long double, long double, int *);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double rintl(long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double roundl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double scalbnl(long double, int);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double scalblnl(long double, long);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double tgammal(long double);
  _Pragma("function_effects = no_state, always_returns")    __intrinsic __nounwind long double truncl(long double);

  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double cosl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double coshl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double logl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double log10l(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double sinl(long double);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind long double sinhl(long double);

                   
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_tan_accurate(double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_cos_accurate(double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_sin_accurate(double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_pow_accurate(double, double);

  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_Sin_accurate(double, unsigned int);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_Pow_accurate(double, double, short *pex);
      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_tan_accuratef(float);
      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_cos_accuratef(float);
      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_sin_accuratef(float);
      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_pow_accuratef(float, float);

      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_Sin_accuratef(float, unsigned int);
      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_Pow_accuratef(float, float, short *pex);

      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_tan_accuratel(long double);
      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_cos_accuratel(long double);
      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_sin_accuratel(long double);
      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_pow_accuratel(long double, 
                                                            long double);

      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_Sin_accuratel(long double, 
                                                            unsigned int);
      _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_Pow_accuratel(long double, 
                                                            long double,
                                                            short *pex);

                   
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_cos_small(double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_exp_small(double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_log_small(double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_log2_small(double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_log10_small(double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_pow_small(double, double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_sin_small(double);
  _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind double __iar_tan_small(double);
  
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_cos_smallf(float);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_exp_smallf(float);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_log_smallf(float);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_log2_smallf(float);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_log10_smallf(float);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_pow_smallf(float, float);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_sin_smallf(float);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind float __iar_tan_smallf(float);

    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_cos_smalll(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_exp_smalll(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_log_smalll(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_log2_smalll(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_log10_smalll(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_pow_smalll(long double, long double);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_sin_smalll(long double);
    _Pragma("function_effects = no_state, write_errno, always_returns") __intrinsic __nounwind long double __iar_tan_smalll(long double);










                 

 

  #pragma inline=no_body
  double cos(double _X)
  {        
    return __iar_Sin(_X, 1);
  }

  #pragma inline=no_body
  double cosh(double _X)
  {        
    return __iar_Cosh(_X, 1);
  }

  #pragma inline=no_body
  double log(double _X)
  {        
    return __iar_Log(_X, 0);
  }

  #pragma inline=no_body
  double log10(double _X)
  {        
    return __iar_Log(_X, 1);
  }

  #pragma inline=no_body
  double sin(double _X)
  {        
    return __iar_Sin(_X, 0);
  }

  #pragma inline=no_body
  double sinh(double _X)
  {        
    return __iar_Sinh(_X, 1);
  }


                 
    #pragma inline=no_body
    double log2(double _Left)
    {    
      return (__iar_Log(_Left, -1));
    }

    #pragma inline=no_body
    double nan(const char *s)
    {    
      return (0.Nan);
    }

    #pragma inline=no_body
    double nextafter(double x, double y)
    {    
      return (nexttoward(x, (long double)y));
    }

    #pragma inline=no_body
    double remainder(double x, double y)
    {    
      return (remquo(x, y, 0));
    }


                 
    #pragma inline=no_body
    float cosf(float _X)
    {        
      return (__iar_FSin(_X, 1));
    }

    #pragma inline=no_body
    float coshf(float _X)
    {        
      return (__iar_FCosh(_X,  1.0F));
    }

    #pragma inline=no_body
    float logf(float _X)
    {        
      return (__iar_FLog(_X, 0));
    }

    #pragma inline=no_body 
    float log2f(float _Left)
    {        
      return (__iar_FLog(_Left, -1));
    }

    #pragma inline=no_body
    float log10f(float _X)
    {        
      return (__iar_FLog(_X, 1));
    }

    #pragma inline=no_body
    float nanf(const char *s)
    {    
      return (0.Nan);
    }

    #pragma inline=no_body
    float nextafterf(float x, float y)
    {    
      return (nexttowardf(x, (long double)y));
    }

    #pragma inline=no_body
    float remainderf(float x, float y)
    {    
      return (remquof(x, y, 0));
    }

    #pragma inline=no_body
    float sinf(float _X)
    {        
      return (__iar_FSin(_X, 0));
    }

    #pragma inline=no_body
    float sinhf(float _X)
    {        
      return (__iar_FSinh(_X,  1.0F));
    }

                 
    #pragma inline=no_body
    long double cosl(long double _X)
    {        
      return (__iar_Sin(_X, 1));
    }

    #pragma inline=no_body
    long double coshl(long double _X)
    {        
      return (__iar_Cosh(_X, (double) 1.0L));
    }

    #pragma inline=no_body
    long double logl(long double _X)
    {        
      return (__iar_Log(_X, 0));
    }

    #pragma inline=no_body 
    long double log2l(long double _Left)
    {        
      return (__iar_Log(_Left, -1));
    }

    #pragma inline=no_body
    long double log10l(long double _X)
    {        
      return (__iar_Log(_X, 1));
    }

    #pragma inline=no_body
    long double nanl(const char *s)
    {    
      return (0.Nan);
    }

    #pragma inline=no_body
    long double nextafterl(long double x, long double y)
    {    
      return (nexttowardl(x, y));
    }

    #pragma inline=no_body
    long double remainderl(long double x, long double y)
    {    
      return (remquol(x, y, 0));
    }

    #pragma inline=no_body
    long double sinl(long double _X)
    {        
      return (__iar_Sin(_X, 0));
    }

    #pragma inline=no_body
    long double sinhl(long double _X)
    {        
      return (__iar_Sinh(_X, (double) 1.0L));
    }



   






   
  
  
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind int __iar_Dcomp(double, double);
    _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind int __iar_FDcomp(float, float);
  
  
  
      


    

  #pragma inline=no_body
  int __iar_Dcomp(double x, double y)
  {
    if ((__c99_generic(x,,, __iar_Dtest, __iar_FDtest, __iar_Dtest,,,)(x) == 2) || (__c99_generic(y,,, __iar_Dtest, __iar_FDtest, __iar_Dtest,,,)(y) == 2))
    {
      return 0;
    }
    if (x > y)
    {
      return 4;
    }
    if (x < y)
    {
      return 1;
    }
    if (x == y)
    {
      return 2;
    }
    return 0;
  }

    #pragma inline=no_body
    int __iar_FDcomp(float x, float y)
    {
      if ((__c99_generic(x,,, __iar_Dtest, __iar_FDtest, __iar_Dtest,,,)(x) == 2) || (__c99_generic(y,,, __iar_Dtest, __iar_FDtest, __iar_Dtest,,,)(y) == 2))
      {
        return 0;
      }
      if (x > y)
      {
        return 4;
      }
      if (x < y)
      {
        return 1;
      }
      if (x == y)
      {
        return 2;
      }
      return 0;
    }




                 







 


  

 


  

 


  

 
   
   

  

 

  

 

  typedef enum
  {
    ARM_MATH_SUCCESS = 0,                 
    ARM_MATH_ARGUMENT_ERROR = -1,         
    ARM_MATH_LENGTH_ERROR = -2,           
    ARM_MATH_SIZE_MISMATCH = -3,          
    ARM_MATH_NANINF = -4,                 
    ARM_MATH_SINGULAR = -5,               
    ARM_MATH_TEST_FAILURE = -6            
  } arm_status;

  

 
  typedef int8_t q7_t;

  

 
  typedef int16_t q15_t;

  

 
  typedef int32_t q31_t;

  

 
  typedef int64_t q63_t;

  

 
  typedef float float32_t;

  

 
  typedef double float64_t;

  

 



  

 



   

 



  

 
  static inline q31_t clip_q63_to_q31(
  q63_t x)
  {
    return ((q31_t) (x >> 32) != ((q31_t) x >> 31)) ?
      ((0x7FFFFFFF ^ ((q31_t) (x >> 63)))) : (q31_t) x;
  }

  

 
  static inline q15_t clip_q63_to_q15(
  q63_t x)
  {
    return ((q31_t) (x >> 32) != ((q31_t) x >> 31)) ?
      ((0x7FFF ^ ((q15_t) (x >> 63)))) : (q15_t) (x >> 15);
  }

  

 
  static inline q7_t clip_q31_to_q7(
  q31_t x)
  {
    return ((q31_t) (x >> 24) != ((q31_t) x >> 23)) ?
      ((0x7F ^ ((q7_t) (x >> 31)))) : (q7_t) x;
  }

  

 
  static inline q15_t clip_q31_to_q15(
  q31_t x)
  {
    return ((q31_t) (x >> 16) != ((q31_t) x >> 15)) ?
      ((0x7FFF ^ ((q15_t) (x >> 31)))) : (q15_t) x;
  }

  

 

  static inline q63_t mult32x64(
  q63_t x,
  q31_t y)
  {
    return ((((q63_t) (x & 0x00000000FFFFFFFF) * y) >> 32) +
            (((q63_t) (x >> 32) * y)));
  }





 
 
  static inline uint32_t __cmsis_iar_clz(
  q31_t data);

  static inline uint32_t __cmsis_iar_clz(
  q31_t data)
  {
    uint32_t count = 0;
    uint32_t mask = 0x80000000;

    while((data & mask) == 0)
    {
      count += 1u;
      mask = mask >> 1u;
    }

    return (count);
  }

  

 

  static inline uint32_t arm_recip_q31(
  q31_t in,
  q31_t * dst,
  q31_t * pRecipTable)
  {
    q31_t out;
    uint32_t tempVal;
    uint32_t index, i;
    uint32_t signBits;

    if(in > 0)
    {
      signBits = ((uint32_t) (__cmsis_iar_clz( in) - 1));
    }
    else
    {
      signBits = ((uint32_t) (__cmsis_iar_clz(-in) - 1));
    }

     
    in = (in << signBits);

     
    index = (uint32_t)(in >> 24);
    index = (index & 0x0000003F);

     
    out = pRecipTable[index];

     
     
    for (i = 0u; i < 2u; i++)
    {
      tempVal = (uint32_t) (((q63_t) in * out) >> 31);
      tempVal = 0x7FFFFFFFu - tempVal;
       
       
      out = clip_q63_to_q31(((q63_t) out * tempVal) >> 30);
    }

     
    *dst = out;

     
    return (signBits + 1u);
  }


  

 
  static inline uint32_t arm_recip_q15(
  q15_t in,
  q15_t * dst,
  q15_t * pRecipTable)
  {
    q15_t out = 0;
    uint32_t tempVal = 0;
    uint32_t index = 0, i = 0;
    uint32_t signBits = 0;

    if(in > 0)
    {
      signBits = ((uint32_t)(__cmsis_iar_clz( in) - 17));
    }
    else
    {
      signBits = ((uint32_t)(__cmsis_iar_clz(-in) - 17));
    }

     
    in = (in << signBits);

     
    index = (uint32_t)(in >>  8);
    index = (index & 0x0000003F);

     
    out = pRecipTable[index];

     
     
    for (i = 0u; i < 2u; i++)
    {
      tempVal = (uint32_t) (((q31_t) in * out) >> 15);
      tempVal = 0x7FFFu - tempVal;
       
      out = (q15_t) (((q31_t) out * tempVal) >> 14);
       
    }

     
    *dst = out;

     
    return (signBits + 1);
  }


  

 
  static inline q31_t __cmsis_iar_ssat(
  q31_t x,
  uint32_t y)
  {
    int32_t posMax, negMin;
    uint32_t i;

    posMax = 1;
    for (i = 0; i < (y - 1); i++)
    {
      posMax = posMax * 2;
    }

    if(x > 0)
    {
      posMax = (posMax - 1);

      if(x > posMax)
      {
        x = posMax;
      }
    }
    else
    {
      negMin = -posMax;

      if(x < negMin)
      {
        x = negMin;
      }
    }
    return (x);
  }


  

 

  

 
  static inline uint32_t __QADD8(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s, t, u;

    r = __cmsis_iar_ssat(((((q31_t)x << 24) >> 24) + (((q31_t)y << 24) >> 24)), 8) & (int32_t)0x000000FF;
    s = __cmsis_iar_ssat(((((q31_t)x << 16) >> 24) + (((q31_t)y << 16) >> 24)), 8) & (int32_t)0x000000FF;
    t = __cmsis_iar_ssat(((((q31_t)x <<  8) >> 24) + (((q31_t)y <<  8) >> 24)), 8) & (int32_t)0x000000FF;
    u = __cmsis_iar_ssat(((((q31_t)x      ) >> 24) + (((q31_t)y      ) >> 24)), 8) & (int32_t)0x000000FF;

    return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
  }


  

 
  static inline uint32_t __QSUB8(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s, t, u;

    r = __cmsis_iar_ssat(((((q31_t)x << 24) >> 24) - (((q31_t)y << 24) >> 24)), 8) & (int32_t)0x000000FF;
    s = __cmsis_iar_ssat(((((q31_t)x << 16) >> 24) - (((q31_t)y << 16) >> 24)), 8) & (int32_t)0x000000FF;
    t = __cmsis_iar_ssat(((((q31_t)x <<  8) >> 24) - (((q31_t)y <<  8) >> 24)), 8) & (int32_t)0x000000FF;
    u = __cmsis_iar_ssat(((((q31_t)x      ) >> 24) - (((q31_t)y      ) >> 24)), 8) & (int32_t)0x000000FF;

    return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
  }


  

 
  static inline uint32_t __QADD16(
  uint32_t x,
  uint32_t y)
  {
 
    q31_t r = 0, s = 0;

    r = __cmsis_iar_ssat(((((q31_t)x << 16) >> 16) + (((q31_t)y << 16) >> 16)), 16) & (int32_t)0x0000FFFF;
    s = __cmsis_iar_ssat(((((q31_t)x      ) >> 16) + (((q31_t)y      ) >> 16)), 16) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


  

 
  static inline uint32_t __SHADD16(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = (((((q31_t)x << 16) >> 16) + (((q31_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;
    s = (((((q31_t)x      ) >> 16) + (((q31_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


  

 
  static inline uint32_t __QSUB16(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = __cmsis_iar_ssat(((((q31_t)x << 16) >> 16) - (((q31_t)y << 16) >> 16)), 16) & (int32_t)0x0000FFFF;
    s = __cmsis_iar_ssat(((((q31_t)x      ) >> 16) - (((q31_t)y      ) >> 16)), 16) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


  

 
  static inline uint32_t __SHSUB16(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = (((((q31_t)x << 16) >> 16) - (((q31_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;
    s = (((((q31_t)x      ) >> 16) - (((q31_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


  

 
  static inline uint32_t __QASX(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = __cmsis_iar_ssat(((((q31_t)x << 16) >> 16) - (((q31_t)y      ) >> 16)), 16) & (int32_t)0x0000FFFF;
    s = __cmsis_iar_ssat(((((q31_t)x      ) >> 16) + (((q31_t)y << 16) >> 16)), 16) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


  

 
  static inline uint32_t __SHASX(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = (((((q31_t)x << 16) >> 16) - (((q31_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;
    s = (((((q31_t)x      ) >> 16) + (((q31_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


  

 
  static inline uint32_t __QSAX(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = __cmsis_iar_ssat(((((q31_t)x << 16) >> 16) + (((q31_t)y      ) >> 16)), 16) & (int32_t)0x0000FFFF;
    s = __cmsis_iar_ssat(((((q31_t)x      ) >> 16) - (((q31_t)y << 16) >> 16)), 16) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


  

 
  static inline uint32_t __SHSAX(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = (((((q31_t)x << 16) >> 16) + (((q31_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;
    s = (((((q31_t)x      ) >> 16) - (((q31_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


  

 
  static inline uint32_t __SMUSDX(
  uint32_t x,
  uint32_t y)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) -
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16))   ));
  }

  

 
  static inline uint32_t __SMUADX(
  uint32_t x,
  uint32_t y)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16))   ));
  }


  

 
  static inline int32_t __QADD(
  int32_t x,
  int32_t y)
  {
    return ((int32_t)(clip_q63_to_q31((q63_t)x + (q31_t)y)));
  }


  

 
  static inline int32_t __QSUB(
  int32_t x,
  int32_t y)
  {
    return ((int32_t)(clip_q63_to_q31((q63_t)x - (q31_t)y)));
  }


  

 
  static inline uint32_t __SMLAD(
  uint32_t x,
  uint32_t y,
  uint32_t sum)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y      ) >> 16)) +
                       ( ((q31_t)sum    )                                  )   ));
  }


  

 
  static inline uint32_t __SMLADX(
  uint32_t x,
  uint32_t y,
  uint32_t sum)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ( ((q31_t)sum    )                                  )   ));
  }


  

 
  static inline uint32_t __SMLSDX(
  uint32_t x,
  uint32_t y,
  uint32_t sum)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) -
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ( ((q31_t)sum    )                                  )   ));
  }


  

 
  static inline uint64_t __SMLALD(
  uint32_t x,
  uint32_t y,
  uint64_t sum)
  {
 
    return ((uint64_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y      ) >> 16)) +
                       ( ((q63_t)sum    )                                  )   ));
  }


  

 
  static inline uint64_t __SMLALDX(
  uint32_t x,
  uint32_t y,
  uint64_t sum)
  {
 
    return ((uint64_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ( ((q63_t)sum    )                                  )   ));
  }


  

 
  static inline uint32_t __SMUAD(
  uint32_t x,
  uint32_t y)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y      ) >> 16))   ));
  }


  

 
  static inline uint32_t __SMUSD(
  uint32_t x,
  uint32_t y)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y << 16) >> 16)) -
                       ((((q31_t)x      ) >> 16) * (((q31_t)y      ) >> 16))   ));
  }


  

 
  static inline uint32_t __SXTB16(
  uint32_t x)
  {
    return ((uint32_t)(((((q31_t)x << 24) >> 24) & (q31_t)0x0000FFFF) |
                       ((((q31_t)x <<  8) >>  8) & (q31_t)0xFFFF0000)  ));
  }



  

 
  typedef struct
  {
    uint16_t numTaps;         
    q7_t *pState;             
    q7_t *pCoeffs;            
  } arm_fir_instance_q7;

  

 
  typedef struct
  {
    uint16_t numTaps;          
    q15_t *pState;             
    q15_t *pCoeffs;            
  } arm_fir_instance_q15;

  

 
  typedef struct
  {
    uint16_t numTaps;          
    q31_t *pState;             
    q31_t *pCoeffs;            
  } arm_fir_instance_q31;

  

 
  typedef struct
  {
    uint16_t numTaps;      
    float32_t *pState;     
    float32_t *pCoeffs;    
  } arm_fir_instance_f32;


  





 
  void arm_fir_q7(
  const arm_fir_instance_q7 * S,
  q7_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);


  






 
  void arm_fir_init_q7(
  arm_fir_instance_q7 * S,
  uint16_t numTaps,
  q7_t * pCoeffs,
  q7_t * pState,
  uint32_t blockSize);


  





 
  void arm_fir_q15(
  const arm_fir_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  





 
  void arm_fir_fast_q15(
  const arm_fir_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  








 
  arm_status arm_fir_init_q15(
  arm_fir_instance_q15 * S,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  uint32_t blockSize);


  





 
  void arm_fir_q31(
  const arm_fir_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  





 
  void arm_fir_fast_q31(
  const arm_fir_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  






 
  void arm_fir_init_q31(
  arm_fir_instance_q31 * S,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  uint32_t blockSize);


  





 
  void arm_fir_f32(
  const arm_fir_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  






 
  void arm_fir_init_f32(
  arm_fir_instance_f32 * S,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  uint32_t blockSize);


  

 
  typedef struct
  {
    int8_t numStages;         
    q15_t *pState;            
    q15_t *pCoeffs;           
    int8_t postShift;         
  } arm_biquad_casd_df1_inst_q15;

  

 
  typedef struct
  {
    uint32_t numStages;       
    q31_t *pState;            
    q31_t *pCoeffs;           
    uint8_t postShift;        
  } arm_biquad_casd_df1_inst_q31;

  

 
  typedef struct
  {
    uint32_t numStages;       
    float32_t *pState;        
    float32_t *pCoeffs;       
  } arm_biquad_casd_df1_inst_f32;


  





 
  void arm_biquad_cascade_df1_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  






 
  void arm_biquad_cascade_df1_init_q15(
  arm_biquad_casd_df1_inst_q15 * S,
  uint8_t numStages,
  q15_t * pCoeffs,
  q15_t * pState,
  int8_t postShift);


  





 
  void arm_biquad_cascade_df1_fast_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  





 
  void arm_biquad_cascade_df1_q31(
  const arm_biquad_casd_df1_inst_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  





 
  void arm_biquad_cascade_df1_fast_q31(
  const arm_biquad_casd_df1_inst_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  






 
  void arm_biquad_cascade_df1_init_q31(
  arm_biquad_casd_df1_inst_q31 * S,
  uint8_t numStages,
  q31_t * pCoeffs,
  q31_t * pState,
  int8_t postShift);


  





 
  void arm_biquad_cascade_df1_f32(
  const arm_biquad_casd_df1_inst_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  





 
  void arm_biquad_cascade_df1_init_f32(
  arm_biquad_casd_df1_inst_f32 * S,
  uint8_t numStages,
  float32_t * pCoeffs,
  float32_t * pState);


  

 
  typedef struct
  {
    uint16_t numRows;      
    uint16_t numCols;      
    float32_t *pData;      
  } arm_matrix_instance_f32;


  

 
  typedef struct
  {
    uint16_t numRows;      
    uint16_t numCols;      
    float64_t *pData;      
  } arm_matrix_instance_f64;

  

 
  typedef struct
  {
    uint16_t numRows;      
    uint16_t numCols;      
    q15_t *pData;          
  } arm_matrix_instance_q15;

  

 
  typedef struct
  {
    uint16_t numRows;      
    uint16_t numCols;      
    q31_t *pData;          
  } arm_matrix_instance_q31;


  






 
  arm_status arm_mat_add_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst);


  






 
  arm_status arm_mat_add_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
  arm_matrix_instance_q15 * pDst);


  






 
  arm_status arm_mat_add_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
  arm_matrix_instance_q31 * pDst);


  






 
  arm_status arm_mat_cmplx_mult_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst);


  






 
  arm_status arm_mat_cmplx_mult_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
  arm_matrix_instance_q15 * pDst,
  q15_t * pScratch);


  






 
  arm_status arm_mat_cmplx_mult_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
  arm_matrix_instance_q31 * pDst);


  





 
  arm_status arm_mat_trans_f32(
  const arm_matrix_instance_f32 * pSrc,
  arm_matrix_instance_f32 * pDst);


  





 
  arm_status arm_mat_trans_q15(
  const arm_matrix_instance_q15 * pSrc,
  arm_matrix_instance_q15 * pDst);


  





 
  arm_status arm_mat_trans_q31(
  const arm_matrix_instance_q31 * pSrc,
  arm_matrix_instance_q31 * pDst);


  






 
  arm_status arm_mat_mult_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst);


  







 
  arm_status arm_mat_mult_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
  arm_matrix_instance_q15 * pDst,
  q15_t * pState);


  







 
  arm_status arm_mat_mult_fast_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
  arm_matrix_instance_q15 * pDst,
  q15_t * pState);


  






 
  arm_status arm_mat_mult_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
  arm_matrix_instance_q31 * pDst);


  






 
  arm_status arm_mat_mult_fast_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
  arm_matrix_instance_q31 * pDst);


  






 
  arm_status arm_mat_sub_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst);


  






 
  arm_status arm_mat_sub_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
  arm_matrix_instance_q15 * pDst);


  






 
  arm_status arm_mat_sub_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
  arm_matrix_instance_q31 * pDst);


  






 
  arm_status arm_mat_scale_f32(
  const arm_matrix_instance_f32 * pSrc,
  float32_t scale,
  arm_matrix_instance_f32 * pDst);


  







 
  arm_status arm_mat_scale_q15(
  const arm_matrix_instance_q15 * pSrc,
  q15_t scaleFract,
  int32_t shift,
  arm_matrix_instance_q15 * pDst);


  







 
  arm_status arm_mat_scale_q31(
  const arm_matrix_instance_q31 * pSrc,
  q31_t scaleFract,
  int32_t shift,
  arm_matrix_instance_q31 * pDst);


  





 
  void arm_mat_init_q31(
  arm_matrix_instance_q31 * S,
  uint16_t nRows,
  uint16_t nColumns,
  q31_t * pData);


  





 
  void arm_mat_init_q15(
  arm_matrix_instance_q15 * S,
  uint16_t nRows,
  uint16_t nColumns,
  q15_t * pData);


  





 
  void arm_mat_init_f32(
  arm_matrix_instance_f32 * S,
  uint16_t nRows,
  uint16_t nColumns,
  float32_t * pData);



  

 
  typedef struct
  {
    q15_t A0;            
    q15_t A1;
    q15_t A2;
    q15_t state[3];      
    q15_t Kp;            
    q15_t Ki;            
    q15_t Kd;            
  } arm_pid_instance_q15;

  

 
  typedef struct
  {
    q31_t A0;             
    q31_t A1;             
    q31_t A2;             
    q31_t state[3];       
    q31_t Kp;             
    q31_t Ki;             
    q31_t Kd;             
  } arm_pid_instance_q31;

  

 
  typedef struct
  {
    float32_t A0;           
    float32_t A1;           
    float32_t A2;           
    float32_t state[3];     
    float32_t Kp;           
    float32_t Ki;           
    float32_t Kd;           
  } arm_pid_instance_f32;



  



 
  void arm_pid_init_f32(
  arm_pid_instance_f32 * S,
  int32_t resetStateFlag);


  


 
  void arm_pid_reset_f32(
  arm_pid_instance_f32 * S);


  



 
  void arm_pid_init_q31(
  arm_pid_instance_q31 * S,
  int32_t resetStateFlag);


  


 

  void arm_pid_reset_q31(
  arm_pid_instance_q31 * S);


  



 
  void arm_pid_init_q15(
  arm_pid_instance_q15 * S,
  int32_t resetStateFlag);


  


 
  void arm_pid_reset_q15(
  arm_pid_instance_q15 * S);


  

 
  typedef struct
  {
    uint32_t nValues;            
    float32_t x1;                
    float32_t xSpacing;          
    float32_t *pYData;           
  } arm_linear_interp_instance_f32;

  

 
  typedef struct
  {
    uint16_t numRows;    
    uint16_t numCols;    
    float32_t *pData;    
  } arm_bilinear_interp_instance_f32;

   

 
  typedef struct
  {
    uint16_t numRows;    
    uint16_t numCols;    
    q31_t *pData;        
  } arm_bilinear_interp_instance_q31;

   

 
  typedef struct
  {
    uint16_t numRows;    
    uint16_t numCols;    
    q15_t *pData;        
  } arm_bilinear_interp_instance_q15;

   

 
  typedef struct
  {
    uint16_t numRows;    
    uint16_t numCols;    
    q7_t *pData;         
  } arm_bilinear_interp_instance_q7;


  





 
  void arm_mult_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  q7_t * pDst,
  uint32_t blockSize);


  





 
  void arm_mult_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  uint32_t blockSize);


  





 
  void arm_mult_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  q31_t * pDst,
  uint32_t blockSize);


  





 
  void arm_mult_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  float32_t * pDst,
  uint32_t blockSize);


  

 
  typedef struct
  {
    uint16_t fftLen;                  
    uint8_t ifftFlag;                 
    uint8_t bitReverseFlag;           
    q15_t *pTwiddle;                  
    uint16_t *pBitRevTable;           
    uint16_t twidCoefModifier;        
    uint16_t bitRevFactor;            
  } arm_cfft_radix2_instance_q15;

 
  arm_status arm_cfft_radix2_init_q15(
  arm_cfft_radix2_instance_q15 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

 
  void arm_cfft_radix2_q15(
  const arm_cfft_radix2_instance_q15 * S,
  q15_t * pSrc);


  

 
  typedef struct
  {
    uint16_t fftLen;                  
    uint8_t ifftFlag;                 
    uint8_t bitReverseFlag;           
    q15_t *pTwiddle;                  
    uint16_t *pBitRevTable;           
    uint16_t twidCoefModifier;        
    uint16_t bitRevFactor;            
  } arm_cfft_radix4_instance_q15;

 
  arm_status arm_cfft_radix4_init_q15(
  arm_cfft_radix4_instance_q15 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

 
  void arm_cfft_radix4_q15(
  const arm_cfft_radix4_instance_q15 * S,
  q15_t * pSrc);

  

 
  typedef struct
  {
    uint16_t fftLen;                  
    uint8_t ifftFlag;                 
    uint8_t bitReverseFlag;           
    q31_t *pTwiddle;                  
    uint16_t *pBitRevTable;           
    uint16_t twidCoefModifier;        
    uint16_t bitRevFactor;            
  } arm_cfft_radix2_instance_q31;

 
  arm_status arm_cfft_radix2_init_q31(
  arm_cfft_radix2_instance_q31 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

 
  void arm_cfft_radix2_q31(
  const arm_cfft_radix2_instance_q31 * S,
  q31_t * pSrc);

  

 
  typedef struct
  {
    uint16_t fftLen;                  
    uint8_t ifftFlag;                 
    uint8_t bitReverseFlag;           
    q31_t *pTwiddle;                  
    uint16_t *pBitRevTable;           
    uint16_t twidCoefModifier;        
    uint16_t bitRevFactor;            
  } arm_cfft_radix4_instance_q31;

 
  void arm_cfft_radix4_q31(
  const arm_cfft_radix4_instance_q31 * S,
  q31_t * pSrc);

 
  arm_status arm_cfft_radix4_init_q31(
  arm_cfft_radix4_instance_q31 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

  

 
  typedef struct
  {
    uint16_t fftLen;                    
    uint8_t ifftFlag;                   
    uint8_t bitReverseFlag;             
    float32_t *pTwiddle;                
    uint16_t *pBitRevTable;             
    uint16_t twidCoefModifier;          
    uint16_t bitRevFactor;              
    float32_t onebyfftLen;              
  } arm_cfft_radix2_instance_f32;

 
  arm_status arm_cfft_radix2_init_f32(
  arm_cfft_radix2_instance_f32 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

 
  void arm_cfft_radix2_f32(
  const arm_cfft_radix2_instance_f32 * S,
  float32_t * pSrc);

  

 
  typedef struct
  {
    uint16_t fftLen;                    
    uint8_t ifftFlag;                   
    uint8_t bitReverseFlag;             
    float32_t *pTwiddle;                
    uint16_t *pBitRevTable;             
    uint16_t twidCoefModifier;          
    uint16_t bitRevFactor;              
    float32_t onebyfftLen;              
  } arm_cfft_radix4_instance_f32;

 
  arm_status arm_cfft_radix4_init_f32(
  arm_cfft_radix4_instance_f32 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

 
  void arm_cfft_radix4_f32(
  const arm_cfft_radix4_instance_f32 * S,
  float32_t * pSrc);

  

 
  typedef struct
  {
    uint16_t fftLen;                    
    const q15_t *pTwiddle;              
    const uint16_t *pBitRevTable;       
    uint16_t bitRevLength;              
  } arm_cfft_instance_q15;

void arm_cfft_q15(
    const arm_cfft_instance_q15 * S,
    q15_t * p1,
    uint8_t ifftFlag,
    uint8_t bitReverseFlag);

  

 
  typedef struct
  {
    uint16_t fftLen;                    
    const q31_t *pTwiddle;              
    const uint16_t *pBitRevTable;       
    uint16_t bitRevLength;              
  } arm_cfft_instance_q31;

void arm_cfft_q31(
    const arm_cfft_instance_q31 * S,
    q31_t * p1,
    uint8_t ifftFlag,
    uint8_t bitReverseFlag);

  

 
  typedef struct
  {
    uint16_t fftLen;                    
    const float32_t *pTwiddle;          
    const uint16_t *pBitRevTable;       
    uint16_t bitRevLength;              
  } arm_cfft_instance_f32;

  void arm_cfft_f32(
  const arm_cfft_instance_f32 * S,
  float32_t * p1,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

  

 
  typedef struct
  {
    uint32_t fftLenReal;                       
    uint8_t ifftFlagR;                         
    uint8_t bitReverseFlagR;                   
    uint32_t twidCoefRModifier;                
    q15_t *pTwiddleAReal;                      
    q15_t *pTwiddleBReal;                      
    const arm_cfft_instance_q15 *pCfft;        
  } arm_rfft_instance_q15;

  arm_status arm_rfft_init_q15(
  arm_rfft_instance_q15 * S,
  uint32_t fftLenReal,
  uint32_t ifftFlagR,
  uint32_t bitReverseFlag);

  void arm_rfft_q15(
  const arm_rfft_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst);

  

 
  typedef struct
  {
    uint32_t fftLenReal;                         
    uint8_t ifftFlagR;                           
    uint8_t bitReverseFlagR;                     
    uint32_t twidCoefRModifier;                  
    q31_t *pTwiddleAReal;                        
    q31_t *pTwiddleBReal;                        
    const arm_cfft_instance_q31 *pCfft;          
  } arm_rfft_instance_q31;

  arm_status arm_rfft_init_q31(
  arm_rfft_instance_q31 * S,
  uint32_t fftLenReal,
  uint32_t ifftFlagR,
  uint32_t bitReverseFlag);

  void arm_rfft_q31(
  const arm_rfft_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst);

  

 
  typedef struct
  {
    uint32_t fftLenReal;                         
    uint16_t fftLenBy2;                          
    uint8_t ifftFlagR;                           
    uint8_t bitReverseFlagR;                     
    uint32_t twidCoefRModifier;                      
    float32_t *pTwiddleAReal;                    
    float32_t *pTwiddleBReal;                    
    arm_cfft_radix4_instance_f32 *pCfft;         
  } arm_rfft_instance_f32;

  arm_status arm_rfft_init_f32(
  arm_rfft_instance_f32 * S,
  arm_cfft_radix4_instance_f32 * S_CFFT,
  uint32_t fftLenReal,
  uint32_t ifftFlagR,
  uint32_t bitReverseFlag);

  void arm_rfft_f32(
  const arm_rfft_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst);

  

 
typedef struct
  {
    arm_cfft_instance_f32 Sint;       
    uint16_t fftLenRFFT;              
    float32_t * pTwiddleRFFT;         
  } arm_rfft_fast_instance_f32 ;

arm_status arm_rfft_fast_init_f32 (
   arm_rfft_fast_instance_f32 * S,
   uint16_t fftLen);

void arm_rfft_fast_f32(
  arm_rfft_fast_instance_f32 * S,
  float32_t * p, float32_t * pOut,
  uint8_t ifftFlag);

  

 
  typedef struct
  {
    uint16_t N;                           
    uint16_t Nby2;                        
    float32_t normalize;                  
    float32_t *pTwiddle;                  
    float32_t *pCosFactor;                
    arm_rfft_instance_f32 *pRfft;         
    arm_cfft_radix4_instance_f32 *pCfft;  
  } arm_dct4_instance_f32;


  








 
  arm_status arm_dct4_init_f32(
  arm_dct4_instance_f32 * S,
  arm_rfft_instance_f32 * S_RFFT,
  arm_cfft_radix4_instance_f32 * S_CFFT,
  uint16_t N,
  uint16_t Nby2,
  float32_t normalize);


  




 
  void arm_dct4_f32(
  const arm_dct4_instance_f32 * S,
  float32_t * pState,
  float32_t * pInlineBuffer);


  

 
  typedef struct
  {
    uint16_t N;                           
    uint16_t Nby2;                        
    q31_t normalize;                      
    q31_t *pTwiddle;                      
    q31_t *pCosFactor;                    
    arm_rfft_instance_q31 *pRfft;         
    arm_cfft_radix4_instance_q31 *pCfft;  
  } arm_dct4_instance_q31;


  








 
  arm_status arm_dct4_init_q31(
  arm_dct4_instance_q31 * S,
  arm_rfft_instance_q31 * S_RFFT,
  arm_cfft_radix4_instance_q31 * S_CFFT,
  uint16_t N,
  uint16_t Nby2,
  q31_t normalize);


  




 
  void arm_dct4_q31(
  const arm_dct4_instance_q31 * S,
  q31_t * pState,
  q31_t * pInlineBuffer);


  

 
  typedef struct
  {
    uint16_t N;                           
    uint16_t Nby2;                        
    q15_t normalize;                      
    q15_t *pTwiddle;                      
    q15_t *pCosFactor;                    
    arm_rfft_instance_q15 *pRfft;         
    arm_cfft_radix4_instance_q15 *pCfft;  
  } arm_dct4_instance_q15;


  








 
  arm_status arm_dct4_init_q15(
  arm_dct4_instance_q15 * S,
  arm_rfft_instance_q15 * S_RFFT,
  arm_cfft_radix4_instance_q15 * S_CFFT,
  uint16_t N,
  uint16_t Nby2,
  q15_t normalize);


  




 
  void arm_dct4_q15(
  const arm_dct4_instance_q15 * S,
  q15_t * pState,
  q15_t * pInlineBuffer);


  





 
  void arm_add_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  float32_t * pDst,
  uint32_t blockSize);


  





 
  void arm_add_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  q7_t * pDst,
  uint32_t blockSize);


  





 
  void arm_add_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  uint32_t blockSize);


  





 
  void arm_add_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  q31_t * pDst,
  uint32_t blockSize);


  





 
  void arm_sub_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  float32_t * pDst,
  uint32_t blockSize);


  





 
  void arm_sub_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  q7_t * pDst,
  uint32_t blockSize);


  





 
  void arm_sub_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  uint32_t blockSize);


  





 
  void arm_sub_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  q31_t * pDst,
  uint32_t blockSize);


  





 
  void arm_scale_f32(
  float32_t * pSrc,
  float32_t scale,
  float32_t * pDst,
  uint32_t blockSize);


  






 
  void arm_scale_q7(
  q7_t * pSrc,
  q7_t scaleFract,
  int8_t shift,
  q7_t * pDst,
  uint32_t blockSize);


  






 
  void arm_scale_q15(
  q15_t * pSrc,
  q15_t scaleFract,
  int8_t shift,
  q15_t * pDst,
  uint32_t blockSize);


  






 
  void arm_scale_q31(
  q31_t * pSrc,
  q31_t scaleFract,
  int8_t shift,
  q31_t * pDst,
  uint32_t blockSize);


  




 
  void arm_abs_q7(
  q7_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);


  




 
  void arm_abs_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  




 
  void arm_abs_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  




 
  void arm_abs_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  





 
  void arm_dot_prod_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  uint32_t blockSize,
  float32_t * result);


  





 
  void arm_dot_prod_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  uint32_t blockSize,
  q31_t * result);


  





 
  void arm_dot_prod_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  uint32_t blockSize,
  q63_t * result);


  





 
  void arm_dot_prod_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  uint32_t blockSize,
  q63_t * result);


  





 
  void arm_shift_q7(
  q7_t * pSrc,
  int8_t shiftBits,
  q7_t * pDst,
  uint32_t blockSize);


  





 
  void arm_shift_q15(
  q15_t * pSrc,
  int8_t shiftBits,
  q15_t * pDst,
  uint32_t blockSize);


  





 
  void arm_shift_q31(
  q31_t * pSrc,
  int8_t shiftBits,
  q31_t * pDst,
  uint32_t blockSize);


  





 
  void arm_offset_f32(
  float32_t * pSrc,
  float32_t offset,
  float32_t * pDst,
  uint32_t blockSize);


  





 
  void arm_offset_q7(
  q7_t * pSrc,
  q7_t offset,
  q7_t * pDst,
  uint32_t blockSize);


  





 
  void arm_offset_q15(
  q15_t * pSrc,
  q15_t offset,
  q15_t * pDst,
  uint32_t blockSize);


  





 
  void arm_offset_q31(
  q31_t * pSrc,
  q31_t offset,
  q31_t * pDst,
  uint32_t blockSize);


  




 
  void arm_negate_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  




 
  void arm_negate_q7(
  q7_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);


  




 
  void arm_negate_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  




 
  void arm_negate_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  




 
  void arm_copy_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  




 
  void arm_copy_q7(
  q7_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);


  




 
  void arm_copy_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  




 
  void arm_copy_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  




 
  void arm_fill_f32(
  float32_t value,
  float32_t * pDst,
  uint32_t blockSize);


  




 
  void arm_fill_q7(
  q7_t value,
  q7_t * pDst,
  uint32_t blockSize);


  




 
  void arm_fill_q15(
  q15_t value,
  q15_t * pDst,
  uint32_t blockSize);


  




 
  void arm_fill_q31(
  q31_t value,
  q31_t * pDst,
  uint32_t blockSize);









 
  void arm_conv_f32(
  float32_t * pSrcA,
  uint32_t srcALen,
  float32_t * pSrcB,
  uint32_t srcBLen,
  float32_t * pDst);


  








 
  void arm_conv_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  q15_t * pScratch1,
  q15_t * pScratch2);









 
  void arm_conv_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst);


  






 
  void arm_conv_fast_q15(
          q15_t * pSrcA,
          uint32_t srcALen,
          q15_t * pSrcB,
          uint32_t srcBLen,
          q15_t * pDst);


  








 
  void arm_conv_fast_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  q15_t * pScratch1,
  q15_t * pScratch2);


  






 
  void arm_conv_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst);


  






 
  void arm_conv_fast_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst);


    








 
  void arm_conv_opt_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst,
  q15_t * pScratch1,
  q15_t * pScratch2);


  






 
  void arm_conv_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst);


  









 
  arm_status arm_conv_partial_f32(
  float32_t * pSrcA,
  uint32_t srcALen,
  float32_t * pSrcB,
  uint32_t srcBLen,
  float32_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);


  











 
  arm_status arm_conv_partial_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints,
  q15_t * pScratch1,
  q15_t * pScratch2);


  









 
  arm_status arm_conv_partial_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);


  









 
  arm_status arm_conv_partial_fast_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);


  











 
  arm_status arm_conv_partial_fast_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints,
  q15_t * pScratch1,
  q15_t * pScratch2);


  









 
  arm_status arm_conv_partial_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);


  









 
  arm_status arm_conv_partial_fast_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);


  











 
  arm_status arm_conv_partial_opt_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints,
  q15_t * pScratch1,
  q15_t * pScratch2);












 
  arm_status arm_conv_partial_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);


  

 
  typedef struct
  {
    uint8_t M;                   
    uint16_t numTaps;            
    q15_t *pCoeffs;              
    q15_t *pState;               
  } arm_fir_decimate_instance_q15;

  

 
  typedef struct
  {
    uint8_t M;                   
    uint16_t numTaps;            
    q31_t *pCoeffs;              
    q31_t *pState;               
  } arm_fir_decimate_instance_q31;

  

 
  typedef struct
  {
    uint8_t M;                   
    uint16_t numTaps;            
    float32_t *pCoeffs;          
    float32_t *pState;           
  } arm_fir_decimate_instance_f32;


  





 
  void arm_fir_decimate_f32(
  const arm_fir_decimate_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  









 
  arm_status arm_fir_decimate_init_f32(
  arm_fir_decimate_instance_f32 * S,
  uint16_t numTaps,
  uint8_t M,
  float32_t * pCoeffs,
  float32_t * pState,
  uint32_t blockSize);


  





 
  void arm_fir_decimate_q15(
  const arm_fir_decimate_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  





 
  void arm_fir_decimate_fast_q15(
  const arm_fir_decimate_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  









 
  arm_status arm_fir_decimate_init_q15(
  arm_fir_decimate_instance_q15 * S,
  uint16_t numTaps,
  uint8_t M,
  q15_t * pCoeffs,
  q15_t * pState,
  uint32_t blockSize);


  





 
  void arm_fir_decimate_q31(
  const arm_fir_decimate_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);

  





 
  void arm_fir_decimate_fast_q31(
  arm_fir_decimate_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  









 
  arm_status arm_fir_decimate_init_q31(
  arm_fir_decimate_instance_q31 * S,
  uint16_t numTaps,
  uint8_t M,
  q31_t * pCoeffs,
  q31_t * pState,
  uint32_t blockSize);


  

 
  typedef struct
  {
    uint8_t L;                       
    uint16_t phaseLength;            
    q15_t *pCoeffs;                  
    q15_t *pState;                   
  } arm_fir_interpolate_instance_q15;

  

 
  typedef struct
  {
    uint8_t L;                       
    uint16_t phaseLength;            
    q31_t *pCoeffs;                  
    q31_t *pState;                   
  } arm_fir_interpolate_instance_q31;

  

 
  typedef struct
  {
    uint8_t L;                      
    uint16_t phaseLength;           
    float32_t *pCoeffs;             
    float32_t *pState;              
  } arm_fir_interpolate_instance_f32;


  





 
  void arm_fir_interpolate_q15(
  const arm_fir_interpolate_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  









 
  arm_status arm_fir_interpolate_init_q15(
  arm_fir_interpolate_instance_q15 * S,
  uint8_t L,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  uint32_t blockSize);


  





 
  void arm_fir_interpolate_q31(
  const arm_fir_interpolate_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  









 
  arm_status arm_fir_interpolate_init_q31(
  arm_fir_interpolate_instance_q31 * S,
  uint8_t L,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  uint32_t blockSize);


  





 
  void arm_fir_interpolate_f32(
  const arm_fir_interpolate_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  









 
  arm_status arm_fir_interpolate_init_f32(
  arm_fir_interpolate_instance_f32 * S,
  uint8_t L,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  uint32_t blockSize);


  

 
  typedef struct
  {
    uint8_t numStages;        
    q63_t *pState;            
    q31_t *pCoeffs;           
    uint8_t postShift;        
  } arm_biquad_cas_df1_32x64_ins_q31;


  




 
  void arm_biquad_cas_df1_32x64_q31(
  const arm_biquad_cas_df1_32x64_ins_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  





 
  void arm_biquad_cas_df1_32x64_init_q31(
  arm_biquad_cas_df1_32x64_ins_q31 * S,
  uint8_t numStages,
  q31_t * pCoeffs,
  q63_t * pState,
  uint8_t postShift);


  

 
  typedef struct
  {
    uint8_t numStages;          
    float32_t *pState;          
    float32_t *pCoeffs;         
  } arm_biquad_cascade_df2T_instance_f32;

  

 
  typedef struct
  {
    uint8_t numStages;          
    float32_t *pState;          
    float32_t *pCoeffs;         
  } arm_biquad_cascade_stereo_df2T_instance_f32;

  

 
  typedef struct
  {
    uint8_t numStages;          
    float64_t *pState;          
    float64_t *pCoeffs;         
  } arm_biquad_cascade_df2T_instance_f64;


  





 
  void arm_biquad_cascade_df2T_f32(
  const arm_biquad_cascade_df2T_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  





 
  void arm_biquad_cascade_stereo_df2T_f32(
  const arm_biquad_cascade_stereo_df2T_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  





 
  void arm_biquad_cascade_df2T_f64(
  const arm_biquad_cascade_df2T_instance_f64 * S,
  float64_t * pSrc,
  float64_t * pDst,
  uint32_t blockSize);


  





 
  void arm_biquad_cascade_df2T_init_f32(
  arm_biquad_cascade_df2T_instance_f32 * S,
  uint8_t numStages,
  float32_t * pCoeffs,
  float32_t * pState);


  





 
  void arm_biquad_cascade_stereo_df2T_init_f32(
  arm_biquad_cascade_stereo_df2T_instance_f32 * S,
  uint8_t numStages,
  float32_t * pCoeffs,
  float32_t * pState);


  





 
  void arm_biquad_cascade_df2T_init_f64(
  arm_biquad_cascade_df2T_instance_f64 * S,
  uint8_t numStages,
  float64_t * pCoeffs,
  float64_t * pState);


  

 
  typedef struct
  {
    uint16_t numStages;                   
    q15_t *pState;                        
    q15_t *pCoeffs;                       
  } arm_fir_lattice_instance_q15;

  

 
  typedef struct
  {
    uint16_t numStages;                   
    q31_t *pState;                        
    q31_t *pCoeffs;                       
  } arm_fir_lattice_instance_q31;

  

 
  typedef struct
  {
    uint16_t numStages;                   
    float32_t *pState;                    
    float32_t *pCoeffs;                   
  } arm_fir_lattice_instance_f32;


  





 
  void arm_fir_lattice_init_q15(
  arm_fir_lattice_instance_q15 * S,
  uint16_t numStages,
  q15_t * pCoeffs,
  q15_t * pState);


  





 
  void arm_fir_lattice_q15(
  const arm_fir_lattice_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  





 
  void arm_fir_lattice_init_q31(
  arm_fir_lattice_instance_q31 * S,
  uint16_t numStages,
  q31_t * pCoeffs,
  q31_t * pState);


  





 
  void arm_fir_lattice_q31(
  const arm_fir_lattice_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);








 
  void arm_fir_lattice_init_f32(
  arm_fir_lattice_instance_f32 * S,
  uint16_t numStages,
  float32_t * pCoeffs,
  float32_t * pState);


  





 
  void arm_fir_lattice_f32(
  const arm_fir_lattice_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  

 
  typedef struct
  {
    uint16_t numStages;                   
    q15_t *pState;                        
    q15_t *pkCoeffs;                      
    q15_t *pvCoeffs;                      
  } arm_iir_lattice_instance_q15;

  

 
  typedef struct
  {
    uint16_t numStages;                   
    q31_t *pState;                        
    q31_t *pkCoeffs;                      
    q31_t *pvCoeffs;                      
  } arm_iir_lattice_instance_q31;

  

 
  typedef struct
  {
    uint16_t numStages;                   
    float32_t *pState;                    
    float32_t *pkCoeffs;                  
    float32_t *pvCoeffs;                  
  } arm_iir_lattice_instance_f32;


  





 
  void arm_iir_lattice_f32(
  const arm_iir_lattice_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  







 
  void arm_iir_lattice_init_f32(
  arm_iir_lattice_instance_f32 * S,
  uint16_t numStages,
  float32_t * pkCoeffs,
  float32_t * pvCoeffs,
  float32_t * pState,
  uint32_t blockSize);


  





 
  void arm_iir_lattice_q31(
  const arm_iir_lattice_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  







 
  void arm_iir_lattice_init_q31(
  arm_iir_lattice_instance_q31 * S,
  uint16_t numStages,
  q31_t * pkCoeffs,
  q31_t * pvCoeffs,
  q31_t * pState,
  uint32_t blockSize);


  





 
  void arm_iir_lattice_q15(
  const arm_iir_lattice_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);










 
  void arm_iir_lattice_init_q15(
  arm_iir_lattice_instance_q15 * S,
  uint16_t numStages,
  q15_t * pkCoeffs,
  q15_t * pvCoeffs,
  q15_t * pState,
  uint32_t blockSize);


  

 
  typedef struct
  {
    uint16_t numTaps;     
    float32_t *pState;    
    float32_t *pCoeffs;   
    float32_t mu;         
  } arm_lms_instance_f32;


  







 
  void arm_lms_f32(
  const arm_lms_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pRef,
  float32_t * pOut,
  float32_t * pErr,
  uint32_t blockSize);


  







 
  void arm_lms_init_f32(
  arm_lms_instance_f32 * S,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  float32_t mu,
  uint32_t blockSize);


  

 
  typedef struct
  {
    uint16_t numTaps;     
    q15_t *pState;        
    q15_t *pCoeffs;       
    q15_t mu;             
    uint32_t postShift;   
  } arm_lms_instance_q15;


  








 
  void arm_lms_init_q15(
  arm_lms_instance_q15 * S,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  q15_t mu,
  uint32_t blockSize,
  uint32_t postShift);


  







 
  void arm_lms_q15(
  const arm_lms_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pRef,
  q15_t * pOut,
  q15_t * pErr,
  uint32_t blockSize);


  

 
  typedef struct
  {
    uint16_t numTaps;     
    q31_t *pState;        
    q31_t *pCoeffs;       
    q31_t mu;             
    uint32_t postShift;   
  } arm_lms_instance_q31;


  







 
  void arm_lms_q31(
  const arm_lms_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pRef,
  q31_t * pOut,
  q31_t * pErr,
  uint32_t blockSize);


  








 
  void arm_lms_init_q31(
  arm_lms_instance_q31 * S,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  q31_t mu,
  uint32_t blockSize,
  uint32_t postShift);


  

 
  typedef struct
  {
    uint16_t numTaps;      
    float32_t *pState;     
    float32_t *pCoeffs;    
    float32_t mu;          
    float32_t energy;      
    float32_t x0;          
  } arm_lms_norm_instance_f32;


  







 
  void arm_lms_norm_f32(
  arm_lms_norm_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pRef,
  float32_t * pOut,
  float32_t * pErr,
  uint32_t blockSize);


  







 
  void arm_lms_norm_init_f32(
  arm_lms_norm_instance_f32 * S,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  float32_t mu,
  uint32_t blockSize);


  

 
  typedef struct
  {
    uint16_t numTaps;      
    q31_t *pState;         
    q31_t *pCoeffs;        
    q31_t mu;              
    uint8_t postShift;     
    q31_t *recipTable;     
    q31_t energy;          
    q31_t x0;              
  } arm_lms_norm_instance_q31;


  







 
  void arm_lms_norm_q31(
  arm_lms_norm_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pRef,
  q31_t * pOut,
  q31_t * pErr,
  uint32_t blockSize);


  








 
  void arm_lms_norm_init_q31(
  arm_lms_norm_instance_q31 * S,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  q31_t mu,
  uint32_t blockSize,
  uint8_t postShift);


  

 
  typedef struct
  {
    uint16_t numTaps;      
    q15_t *pState;         
    q15_t *pCoeffs;        
    q15_t mu;              
    uint8_t postShift;     
    q15_t *recipTable;     
    q15_t energy;          
    q15_t x0;              
  } arm_lms_norm_instance_q15;


  







 
  void arm_lms_norm_q15(
  arm_lms_norm_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pRef,
  q15_t * pOut,
  q15_t * pErr,
  uint32_t blockSize);


  








 
  void arm_lms_norm_init_q15(
  arm_lms_norm_instance_q15 * S,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  q15_t mu,
  uint32_t blockSize,
  uint8_t postShift);


  






 
  void arm_correlate_f32(
  float32_t * pSrcA,
  uint32_t srcALen,
  float32_t * pSrcB,
  uint32_t srcBLen,
  float32_t * pDst);


   







 
  void arm_correlate_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  q15_t * pScratch);


  






 

  void arm_correlate_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst);


  






 

  void arm_correlate_fast_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst);


  







 
  void arm_correlate_fast_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  q15_t * pScratch);


  






 
  void arm_correlate_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst);


  






 
  void arm_correlate_fast_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst);


 








 
  void arm_correlate_opt_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst,
  q15_t * pScratch1,
  q15_t * pScratch2);


  






 
  void arm_correlate_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst);


  

 
  typedef struct
  {
    uint16_t numTaps;              
    uint16_t stateIndex;           
    float32_t *pState;             
    float32_t *pCoeffs;            
    uint16_t maxDelay;             
    int32_t *pTapDelay;            
  } arm_fir_sparse_instance_f32;

  

 
  typedef struct
  {
    uint16_t numTaps;              
    uint16_t stateIndex;           
    q31_t *pState;                 
    q31_t *pCoeffs;                
    uint16_t maxDelay;             
    int32_t *pTapDelay;            
  } arm_fir_sparse_instance_q31;

  

 
  typedef struct
  {
    uint16_t numTaps;              
    uint16_t stateIndex;           
    q15_t *pState;                 
    q15_t *pCoeffs;                
    uint16_t maxDelay;             
    int32_t *pTapDelay;            
  } arm_fir_sparse_instance_q15;

  

 
  typedef struct
  {
    uint16_t numTaps;              
    uint16_t stateIndex;           
    q7_t *pState;                  
    q7_t *pCoeffs;                 
    uint16_t maxDelay;             
    int32_t *pTapDelay;            
  } arm_fir_sparse_instance_q7;


  






 
  void arm_fir_sparse_f32(
  arm_fir_sparse_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  float32_t * pScratchIn,
  uint32_t blockSize);


  








 
  void arm_fir_sparse_init_f32(
  arm_fir_sparse_instance_f32 * S,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  int32_t * pTapDelay,
  uint16_t maxDelay,
  uint32_t blockSize);


  






 
  void arm_fir_sparse_q31(
  arm_fir_sparse_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  q31_t * pScratchIn,
  uint32_t blockSize);


  








 
  void arm_fir_sparse_init_q31(
  arm_fir_sparse_instance_q31 * S,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  int32_t * pTapDelay,
  uint16_t maxDelay,
  uint32_t blockSize);


  







 
  void arm_fir_sparse_q15(
  arm_fir_sparse_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  q15_t * pScratchIn,
  q31_t * pScratchOut,
  uint32_t blockSize);


  








 
  void arm_fir_sparse_init_q15(
  arm_fir_sparse_instance_q15 * S,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  int32_t * pTapDelay,
  uint16_t maxDelay,
  uint32_t blockSize);


  







 
  void arm_fir_sparse_q7(
  arm_fir_sparse_instance_q7 * S,
  q7_t * pSrc,
  q7_t * pDst,
  q7_t * pScratchIn,
  q31_t * pScratchOut,
  uint32_t blockSize);


  








 
  void arm_fir_sparse_init_q7(
  arm_fir_sparse_instance_q7 * S,
  uint16_t numTaps,
  q7_t * pCoeffs,
  q7_t * pState,
  int32_t * pTapDelay,
  uint16_t maxDelay,
  uint32_t blockSize);


  




 
  void arm_sin_cos_f32(
  float32_t theta,
  float32_t * pSinVal,
  float32_t * pCosVal);


  




 
  void arm_sin_cos_q31(
  q31_t theta,
  q31_t * pSinVal,
  q31_t * pCosVal);


  




 
  void arm_cmplx_conj_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t numSamples);

  




 
  void arm_cmplx_conj_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t numSamples);


  




 
  void arm_cmplx_conj_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t numSamples);


  




 
  void arm_cmplx_mag_squared_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t numSamples);


  




 
  void arm_cmplx_mag_squared_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t numSamples);


  




 
  void arm_cmplx_mag_squared_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t numSamples);


 

 

  






















































 

  


 

  




 
  static inline float32_t arm_pid_f32(
  arm_pid_instance_f32 * S,
  float32_t in)
  {
    float32_t out;

     
    out = (S->A0 * in) +
      (S->A1 * S->state[0]) + (S->A2 * S->state[1]) + (S->state[2]);

     
    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;

     
    return (out);

  }

  












 
  static inline q31_t arm_pid_q31(
  arm_pid_instance_q31 * S,
  q31_t in)
  {
    q63_t acc;
    q31_t out;

     
    acc = (q63_t) S->A0 * in;

     
    acc += (q63_t) S->A1 * S->state[0];

     
    acc += (q63_t) S->A2 * S->state[1];

     
    out = (q31_t) (acc >> 31u);

     
    out += S->state[2];

     
    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;

     
    return (out);
  }


  













 
  static inline q15_t arm_pid_q15(
  arm_pid_instance_q15 * S,
  q15_t in)
  {
    q63_t acc;
    q15_t out;

     
    acc = ((q31_t) S->A0) * in;

     
    acc += (q31_t) S->A1 * S->state[0];
    acc += (q31_t) S->A2 * S->state[1];

     
    acc += (q31_t) S->state[2] << 15;

     
    out = (q15_t) (__cmsis_iar_ssat((acc >> 15), 16));

     
    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;

     
    return (out);
  }

  

 


  





 
  arm_status arm_mat_inverse_f32(
  const arm_matrix_instance_f32 * src,
  arm_matrix_instance_f32 * dst);


  





 
  arm_status arm_mat_inverse_f64(
  const arm_matrix_instance_f64 * src,
  arm_matrix_instance_f64 * dst);



  

 

  



















 

  


 

  






 
  static inline void arm_clarke_f32(
  float32_t Ia,
  float32_t Ib,
  float32_t * pIalpha,
  float32_t * pIbeta)
  {
     
    *pIalpha = Ia;

     
    *pIbeta = ((float32_t) 0.57735026919 * Ia + (float32_t) 1.15470053838 * Ib);
  }


  











 
  static inline void arm_clarke_q31(
  q31_t Ia,
  q31_t Ib,
  q31_t * pIalpha,
  q31_t * pIbeta)
  {
    q31_t product1, product2;                     

     
    *pIalpha = Ia;

     
    product1 = (q31_t) (((q63_t) Ia * 0x24F34E8B) >> 30);

     
    product2 = (q31_t) (((q63_t) Ib * 0x49E69D16) >> 30);

     
    *pIbeta = __QADD(product1, product2);
  }

  

 

  




 
  void arm_q7_to_q31(
  q7_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);



  

 

  













 

  


 

   





 
  static inline void arm_inv_clarke_f32(
  float32_t Ialpha,
  float32_t Ibeta,
  float32_t * pIa,
  float32_t * pIb)
  {
     
    *pIa = Ialpha;

     
    *pIb = -0.5f * Ialpha + 0.8660254039f * Ibeta;
  }


  











 
  static inline void arm_inv_clarke_q31(
  q31_t Ialpha,
  q31_t Ibeta,
  q31_t * pIa,
  q31_t * pIb)
  {
    q31_t product1, product2;                     

     
    *pIa = Ialpha;

     
    product1 = (q31_t) (((q63_t) (Ialpha) * (0x40000000)) >> 31);

     
    product2 = (q31_t) (((q63_t) (Ibeta) * (0x6ED9EBA1)) >> 31);

     
    *pIb = __QSUB(product2, product1);
  }

  

 

  




 
  void arm_q7_to_q15(
  q7_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);



  

 

  





















 

  


 

  










 
  static inline void arm_park_f32(
  float32_t Ialpha,
  float32_t Ibeta,
  float32_t * pId,
  float32_t * pIq,
  float32_t sinVal,
  float32_t cosVal)
  {
     
    *pId = Ialpha * cosVal + Ibeta * sinVal;

     
    *pIq = -Ialpha * sinVal + Ibeta * cosVal;
  }


  













 
  static inline void arm_park_q31(
  q31_t Ialpha,
  q31_t Ibeta,
  q31_t * pId,
  q31_t * pIq,
  q31_t sinVal,
  q31_t cosVal)
  {
    q31_t product1, product2;                     
    q31_t product3, product4;                     

     
    product1 = (q31_t) (((q63_t) (Ialpha) * (cosVal)) >> 31);

     
    product2 = (q31_t) (((q63_t) (Ibeta) * (sinVal)) >> 31);


     
    product3 = (q31_t) (((q63_t) (Ialpha) * (sinVal)) >> 31);

     
    product4 = (q31_t) (((q63_t) (Ibeta) * (cosVal)) >> 31);

     
    *pId = __QADD(product1, product2);

     
    *pIq = __QSUB(product4, product3);
  }

  

 

  




 
  void arm_q7_to_float(
  q7_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  

 

  














 

  


 

   







 
  static inline void arm_inv_park_f32(
  float32_t Id,
  float32_t Iq,
  float32_t * pIalpha,
  float32_t * pIbeta,
  float32_t sinVal,
  float32_t cosVal)
  {
     
    *pIalpha = Id * cosVal - Iq * sinVal;

     
    *pIbeta = Id * sinVal + Iq * cosVal;
  }


  













 
  static inline void arm_inv_park_q31(
  q31_t Id,
  q31_t Iq,
  q31_t * pIalpha,
  q31_t * pIbeta,
  q31_t sinVal,
  q31_t cosVal)
  {
    q31_t product1, product2;                     
    q31_t product3, product4;                     

     
    product1 = (q31_t) (((q63_t) (Id) * (cosVal)) >> 31);

     
    product2 = (q31_t) (((q63_t) (Iq) * (sinVal)) >> 31);


     
    product3 = (q31_t) (((q63_t) (Id) * (sinVal)) >> 31);

     
    product4 = (q31_t) (((q63_t) (Iq) * (cosVal)) >> 31);

     
    *pIalpha = __QSUB(product1, product2);

     
    *pIbeta = __QADD(product4, product3);
  }

  

 


  




 
  void arm_q31_to_float(
  q31_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);

  

 

  





























 

  


 

  





 
  static inline float32_t arm_linear_interp_f32(
  arm_linear_interp_instance_f32 * S,
  float32_t x)
  {
    float32_t y;
    float32_t x0, x1;                             
    float32_t y0, y1;                             
    float32_t xSpacing = S->xSpacing;             
    int32_t i;                                    
    float32_t *pYData = S->pYData;                

     
    i = (int32_t) ((x - S->x1) / xSpacing);

    if(i < 0)
    {
       
      y = pYData[0];
    }
    else if((uint32_t)i >= S->nValues)
    {
       
      y = pYData[S->nValues - 1];
    }
    else
    {
       
      x0 = S->x1 +  i      * xSpacing;
      x1 = S->x1 + (i + 1) * xSpacing;

       
      y0 = pYData[i];
      y1 = pYData[i + 1];

       
      y = y0 + (x - x0) * ((y1 - y0) / (x1 - x0));

    }

     
    return (y);
  }


   











 
  static inline q31_t arm_linear_interp_q31(
  q31_t * pYData,
  q31_t x,
  uint32_t nValues)
  {
    q31_t y;                                      
    q31_t y0, y1;                                 
    q31_t fract;                                  
    int32_t index;                                

     
     
     
    index = ((x & (q31_t)0xFFF00000) >> 20);

    if(index >= (int32_t)(nValues - 1))
    {
      return (pYData[nValues - 1]);
    }
    else if(index < 0)
    {
      return (pYData[0]);
    }
    else
    {
       
       
      fract = (x & 0x000FFFFF) << 11;

       
      y0 = pYData[index];
      y1 = pYData[index + 1];

       
      y = ((q31_t) ((q63_t) y0 * (0x7FFFFFFF - fract) >> 32));

       
      y += ((q31_t) (((q63_t) y1 * fract) >> 32));

       
      return (y << 1u);
    }
  }


  











 
  static inline q15_t arm_linear_interp_q15(
  q15_t * pYData,
  q31_t x,
  uint32_t nValues)
  {
    q63_t y;                                      
    q15_t y0, y1;                                 
    q31_t fract;                                  
    int32_t index;                                

     
     
     
    index = ((x & (int32_t)0xFFF00000) >> 20);

    if(index >= (int32_t)(nValues - 1))
    {
      return (pYData[nValues - 1]);
    }
    else if(index < 0)
    {
      return (pYData[0]);
    }
    else
    {
       
       
      fract = (x & 0x000FFFFF);

       
      y0 = pYData[index];
      y1 = pYData[index + 1];

       
      y = ((q63_t) y0 * (0xFFFFF - fract));

       
      y += ((q63_t) y1 * (fract));

       
      return (q15_t) (y >> 20);
    }
  }


  










 
  static inline q7_t arm_linear_interp_q7(
  q7_t * pYData,
  q31_t x,
  uint32_t nValues)
  {
    q31_t y;                                      
    q7_t y0, y1;                                  
    q31_t fract;                                  
    uint32_t index;                               

     
     
     
    if (x < 0)
    {
      return (pYData[0]);
    }
    index = (x >> 20) & 0xfff;

    if(index >= (nValues - 1))
    {
      return (pYData[nValues - 1]);
    }
    else
    {
       
       
      fract = (x & 0x000FFFFF);

       
      y0 = pYData[index];
      y1 = pYData[index + 1];

       
      y = ((y0 * (0xFFFFF - fract)));

       
      y += (y1 * fract);

       
      return (q7_t) (y >> 20);
     }
  }

  

 

  



 
  float32_t arm_sin_f32(
  float32_t x);


  



 
  q31_t arm_sin_q31(
  q31_t x);


  



 
  q15_t arm_sin_q15(
  q15_t x);


  



 
  float32_t arm_cos_f32(
  float32_t x);


  



 
  q31_t arm_cos_q31(
  q31_t x);


  



 
  q15_t arm_cos_q15(
  q15_t x);


  

 


  

















 


  


 

  





 
  static inline arm_status arm_sqrt_f32(
  float32_t in,
  float32_t * pOut)
  {
    if(in >= 0.0f)
    {

      *pOut = sqrtf(in);

      return (ARM_MATH_SUCCESS);
    }
    else
    {
      *pOut = 0.0f;
      return (ARM_MATH_ARGUMENT_ERROR);
    }
  }


  





 
  arm_status arm_sqrt_q31(
  q31_t in,
  q31_t * pOut);


  





 
  arm_status arm_sqrt_q15(
  q15_t in,
  q15_t * pOut);

  

 


  

 
  static inline void arm_circularWrite_f32(
  int32_t * circBuffer,
  int32_t L,
  uint16_t * writeOffset,
  int32_t bufferInc,
  const int32_t * src,
  int32_t srcInc,
  uint32_t blockSize)
  {
    uint32_t i = 0u;
    int32_t wOffset;

    
 
    wOffset = *writeOffset;

     
    i = blockSize;

    while(i > 0u)
    {
       
      circBuffer[wOffset] = *src;

       
      src += srcInc;

       
      wOffset += bufferInc;
      if(wOffset >= L)
        wOffset -= L;

       
      i--;
    }

     
    *writeOffset = (uint16_t)wOffset;
  }



  

 
  static inline void arm_circularRead_f32(
  int32_t * circBuffer,
  int32_t L,
  int32_t * readOffset,
  int32_t bufferInc,
  int32_t * dst,
  int32_t * dst_base,
  int32_t dst_length,
  int32_t dstInc,
  uint32_t blockSize)
  {
    uint32_t i = 0u;
    int32_t rOffset, dst_end;

    
 
    rOffset = *readOffset;
    dst_end = (int32_t) (dst_base + dst_length);

     
    i = blockSize;

    while(i > 0u)
    {
       
      *dst = circBuffer[rOffset];

       
      dst += dstInc;

      if(dst == (int32_t *) dst_end)
      {
        dst = dst_base;
      }

       
      rOffset += bufferInc;

      if(rOffset >= L)
      {
        rOffset -= L;
      }

       
      i--;
    }

     
    *readOffset = rOffset;
  }


  

 
  static inline void arm_circularWrite_q15(
  q15_t * circBuffer,
  int32_t L,
  uint16_t * writeOffset,
  int32_t bufferInc,
  const q15_t * src,
  int32_t srcInc,
  uint32_t blockSize)
  {
    uint32_t i = 0u;
    int32_t wOffset;

    
 
    wOffset = *writeOffset;

     
    i = blockSize;

    while(i > 0u)
    {
       
      circBuffer[wOffset] = *src;

       
      src += srcInc;

       
      wOffset += bufferInc;
      if(wOffset >= L)
        wOffset -= L;

       
      i--;
    }

     
    *writeOffset = (uint16_t)wOffset;
  }


  

 
  static inline void arm_circularRead_q15(
  q15_t * circBuffer,
  int32_t L,
  int32_t * readOffset,
  int32_t bufferInc,
  q15_t * dst,
  q15_t * dst_base,
  int32_t dst_length,
  int32_t dstInc,
  uint32_t blockSize)
  {
    uint32_t i = 0;
    int32_t rOffset, dst_end;

    
 
    rOffset = *readOffset;

    dst_end = (int32_t) (dst_base + dst_length);

     
    i = blockSize;

    while(i > 0u)
    {
       
      *dst = circBuffer[rOffset];

       
      dst += dstInc;

      if(dst == (q15_t *) dst_end)
      {
        dst = dst_base;
      }

       
      rOffset += bufferInc;

      if(rOffset >= L)
      {
        rOffset -= L;
      }

       
      i--;
    }

     
    *readOffset = rOffset;
  }


  

 
  static inline void arm_circularWrite_q7(
  q7_t * circBuffer,
  int32_t L,
  uint16_t * writeOffset,
  int32_t bufferInc,
  const q7_t * src,
  int32_t srcInc,
  uint32_t blockSize)
  {
    uint32_t i = 0u;
    int32_t wOffset;

    
 
    wOffset = *writeOffset;

     
    i = blockSize;

    while(i > 0u)
    {
       
      circBuffer[wOffset] = *src;

       
      src += srcInc;

       
      wOffset += bufferInc;
      if(wOffset >= L)
        wOffset -= L;

       
      i--;
    }

     
    *writeOffset = (uint16_t)wOffset;
  }


  

 
  static inline void arm_circularRead_q7(
  q7_t * circBuffer,
  int32_t L,
  int32_t * readOffset,
  int32_t bufferInc,
  q7_t * dst,
  q7_t * dst_base,
  int32_t dst_length,
  int32_t dstInc,
  uint32_t blockSize)
  {
    uint32_t i = 0;
    int32_t rOffset, dst_end;

    
 
    rOffset = *readOffset;

    dst_end = (int32_t) (dst_base + dst_length);

     
    i = blockSize;

    while(i > 0u)
    {
       
      *dst = circBuffer[rOffset];

       
      dst += dstInc;

      if(dst == (q7_t *) dst_end)
      {
        dst = dst_base;
      }

       
      rOffset += bufferInc;

      if(rOffset >= L)
      {
        rOffset -= L;
      }

       
      i--;
    }

     
    *readOffset = rOffset;
  }


  




 
  void arm_power_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q63_t * pResult);


  




 
  void arm_power_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);


  




 
  void arm_power_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q63_t * pResult);


  




 
  void arm_power_q7(
  q7_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);


  




 
  void arm_mean_q7(
  q7_t * pSrc,
  uint32_t blockSize,
  q7_t * pResult);


  




 
  void arm_mean_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult);


  




 
  void arm_mean_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);


  




 
  void arm_mean_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);


  




 
  void arm_var_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);


  




 
  void arm_var_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);


  




 
  void arm_var_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult);


  




 
  void arm_rms_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);


  




 
  void arm_rms_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);


  




 
  void arm_rms_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult);


  




 
  void arm_std_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);


  




 
  void arm_std_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);


  




 
  void arm_std_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult);


  




 
  void arm_cmplx_mag_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t numSamples);


  




 
  void arm_cmplx_mag_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t numSamples);


  




 
  void arm_cmplx_mag_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t numSamples);


  






 
  void arm_cmplx_dot_prod_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  uint32_t numSamples,
  q31_t * realResult,
  q31_t * imagResult);


  






 
  void arm_cmplx_dot_prod_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  uint32_t numSamples,
  q63_t * realResult,
  q63_t * imagResult);


  






 
  void arm_cmplx_dot_prod_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  uint32_t numSamples,
  float32_t * realResult,
  float32_t * imagResult);


  





 
  void arm_cmplx_mult_real_q15(
  q15_t * pSrcCmplx,
  q15_t * pSrcReal,
  q15_t * pCmplxDst,
  uint32_t numSamples);


  





 
  void arm_cmplx_mult_real_q31(
  q31_t * pSrcCmplx,
  q31_t * pSrcReal,
  q31_t * pCmplxDst,
  uint32_t numSamples);


  





 
  void arm_cmplx_mult_real_f32(
  float32_t * pSrcCmplx,
  float32_t * pSrcReal,
  float32_t * pCmplxDst,
  uint32_t numSamples);


  





 
  void arm_min_q7(
  q7_t * pSrc,
  uint32_t blockSize,
  q7_t * result,
  uint32_t * index);


  





 
  void arm_min_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult,
  uint32_t * pIndex);


  





 
  void arm_min_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult,
  uint32_t * pIndex);


  





 
  void arm_min_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult,
  uint32_t * pIndex);








 
  void arm_max_q7(
  q7_t * pSrc,
  uint32_t blockSize,
  q7_t * pResult,
  uint32_t * pIndex);








 
  void arm_max_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult,
  uint32_t * pIndex);








 
  void arm_max_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult,
  uint32_t * pIndex);








 
  void arm_max_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult,
  uint32_t * pIndex);


  





 
  void arm_cmplx_mult_cmplx_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  uint32_t numSamples);


  





 
  void arm_cmplx_mult_cmplx_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  q31_t * pDst,
  uint32_t numSamples);


  





 
  void arm_cmplx_mult_cmplx_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  float32_t * pDst,
  uint32_t numSamples);


  




 
  void arm_float_to_q31(
  float32_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  




 
  void arm_float_to_q15(
  float32_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  




 
  void arm_float_to_q7(
  float32_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);


  




 
  void arm_q31_to_q15(
  q31_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);


  




 
  void arm_q31_to_q7(
  q31_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);


  




 
  void arm_q15_to_float(
  q15_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);


  




 
  void arm_q15_to_q31(
  q15_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);


  




 
  void arm_q15_to_q7(
  q15_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);


  

 

  

















































 

  


 


  






 
  static inline float32_t arm_bilinear_interp_f32(
  const arm_bilinear_interp_instance_f32 * S,
  float32_t X,
  float32_t Y)
  {
    float32_t out;
    float32_t f00, f01, f10, f11;
    float32_t *pData = S->pData;
    int32_t xIndex, yIndex, index;
    float32_t xdiff, ydiff;
    float32_t b1, b2, b3, b4;

    xIndex = (int32_t) X;
    yIndex = (int32_t) Y;

     
     
    if(xIndex < 0 || xIndex > (S->numRows - 1) || yIndex < 0 || yIndex > (S->numCols - 1))
    {
      return (0);
    }

     
    index = (xIndex - 1) + (yIndex - 1) * S->numCols;


     
    f00 = pData[index];
    f01 = pData[index + 1];

     
    index = (xIndex - 1) + (yIndex) * S->numCols;


     
    f10 = pData[index];
    f11 = pData[index + 1];

     
    b1 = f00;
    b2 = f01 - f00;
    b3 = f10 - f00;
    b4 = f00 - f01 - f10 + f11;

     
    xdiff = X - xIndex;

     
    ydiff = Y - yIndex;

     
    out = b1 + b2 * xdiff + b3 * ydiff + b4 * xdiff * ydiff;

     
    return (out);
  }


  






 
  static inline q31_t arm_bilinear_interp_q31(
  arm_bilinear_interp_instance_q31 * S,
  q31_t X,
  q31_t Y)
  {
    q31_t out;                                    
    q31_t acc = 0;                                
    q31_t xfract, yfract;                         
    q31_t x1, x2, y1, y2;                         
    int32_t rI, cI;                               
    q31_t *pYData = S->pData;                     
    uint32_t nCols = S->numCols;                  

     
     
     
    rI = ((X & (q31_t)0xFFF00000) >> 20);

     
     
     
    cI = ((Y & (q31_t)0xFFF00000) >> 20);

     
     
    if(rI < 0 || rI > (S->numRows - 1) || cI < 0 || cI > (S->numCols - 1))
    {
      return (0);
    }

     
     
    xfract = (X & 0x000FFFFF) << 11u;

     
    x1 = pYData[(rI) + (int32_t)nCols * (cI)    ];
    x2 = pYData[(rI) + (int32_t)nCols * (cI) + 1];

     
     
    yfract = (Y & 0x000FFFFF) << 11u;

     
    y1 = pYData[(rI) + (int32_t)nCols * (cI + 1)    ];
    y2 = pYData[(rI) + (int32_t)nCols * (cI + 1) + 1];

     
    out = ((q31_t) (((q63_t) x1  * (0x7FFFFFFF - xfract)) >> 32));
    acc = ((q31_t) (((q63_t) out * (0x7FFFFFFF - yfract)) >> 32));

     
    out = ((q31_t) ((q63_t) x2 * (0x7FFFFFFF - yfract) >> 32));
    acc += ((q31_t) ((q63_t) out * (xfract) >> 32));

     
    out = ((q31_t) ((q63_t) y1 * (0x7FFFFFFF - xfract) >> 32));
    acc += ((q31_t) ((q63_t) out * (yfract) >> 32));

     
    out = ((q31_t) ((q63_t) y2 * (xfract) >> 32));
    acc += ((q31_t) ((q63_t) out * (yfract) >> 32));

     
    return ((q31_t)(acc << 2));
  }


  





 
  static inline q15_t arm_bilinear_interp_q15(
  arm_bilinear_interp_instance_q15 * S,
  q31_t X,
  q31_t Y)
  {
    q63_t acc = 0;                                
    q31_t out;                                    
    q15_t x1, x2, y1, y2;                         
    q31_t xfract, yfract;                         
    int32_t rI, cI;                               
    q15_t *pYData = S->pData;                     
    uint32_t nCols = S->numCols;                  

     
     
     
    rI = ((X & (q31_t)0xFFF00000) >> 20);

     
     
     
    cI = ((Y & (q31_t)0xFFF00000) >> 20);

     
     
    if(rI < 0 || rI > (S->numRows - 1) || cI < 0 || cI > (S->numCols - 1))
    {
      return (0);
    }

     
     
    xfract = (X & 0x000FFFFF);

     
    x1 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI)    ];
    x2 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI) + 1];

     
     
    yfract = (Y & 0x000FFFFF);

     
    y1 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI + 1)    ];
    y2 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI + 1) + 1];

     

     
     
    out = (q31_t) (((q63_t) x1 * (0xFFFFF - xfract)) >> 4u);
    acc = ((q63_t) out * (0xFFFFF - yfract));

     
    out = (q31_t) (((q63_t) x2 * (0xFFFFF - yfract)) >> 4u);
    acc += ((q63_t) out * (xfract));

     
    out = (q31_t) (((q63_t) y1 * (0xFFFFF - xfract)) >> 4u);
    acc += ((q63_t) out * (yfract));

     
    out = (q31_t) (((q63_t) y2 * (xfract)) >> 4u);
    acc += ((q63_t) out * (yfract));

     
     
    return ((q15_t)(acc >> 36));
  }


  





 
  static inline q7_t arm_bilinear_interp_q7(
  arm_bilinear_interp_instance_q7 * S,
  q31_t X,
  q31_t Y)
  {
    q63_t acc = 0;                                
    q31_t out;                                    
    q31_t xfract, yfract;                         
    q7_t x1, x2, y1, y2;                          
    int32_t rI, cI;                               
    q7_t *pYData = S->pData;                      
    uint32_t nCols = S->numCols;                  

     
     
     
    rI = ((X & (q31_t)0xFFF00000) >> 20);

     
     
     
    cI = ((Y & (q31_t)0xFFF00000) >> 20);

     
     
    if(rI < 0 || rI > (S->numRows - 1) || cI < 0 || cI > (S->numCols - 1))
    {
      return (0);
    }

     
     
    xfract = (X & (q31_t)0x000FFFFF);

     
    x1 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI)    ];
    x2 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI) + 1];

     
     
    yfract = (Y & (q31_t)0x000FFFFF);

     
    y1 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI + 1)    ];
    y2 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI + 1) + 1];

     
    out = ((x1 * (0xFFFFF - xfract)));
    acc = (((q63_t) out * (0xFFFFF - yfract)));

     
    out = ((x2 * (0xFFFFF - yfract)));
    acc += (((q63_t) out * (xfract)));

     
    out = ((y1 * (0xFFFFF - xfract)));
    acc += (((q63_t) out * (yfract)));

     
    out = ((y2 * (yfract)));
    acc += (((q63_t) out * (xfract)));

     
    return ((q7_t)(acc >> 40));
  }

  

 


 

 

 

 

 

 


   

   

   

   










 


 

                

 














 




 







 




 



 




 





 



 




 
void assert_failed(char *, int);




 



                

 

































































 








 




 

 
 

 



                

 














 















 



 
typedef enum
{
     
    PTA0,  PTA1,  PTA2,  PTA3,  PTA4,  PTA5,  PTA6,  PTA7,

     
    PTB0,  PTB1,  PTB2,  PTB3,  PTB4,  PTB5,  PTB6,  PTB7,

     
    PTC0,  PTC1,  PTC2,  PTC3,  PTC4,  PTC5,  PTC6,  PTC7,

     
    PTD0,  PTD1,  PTD2,  PTD3,  PTD4,  PTD5,  PTD6,  PTD7,

     
    PTE0,  PTE1,  PTE2,  PTE3,  PTE4,  PTE5,  PTE6,  PTE7,

     
    PTF0,  PTF1,  PTF2,  PTF3,  PTF4,  PTF5,  PTF6,  PTF7,

     
    PTG0,  PTG1,  PTG2,  PTG3,  PTG4,  PTG5,  PTG6,  PTG7,

     
    PTH0,  PTH1,  PTH2,  PTH3,  PTH4,  PTH5,  PTH6,  PTH7,

     
    PTI0,  PTI1,  PTI2,  PTI3,  PTI4,  PTI5,  PTI6,  PTI7,

    PTXn_MAX

} PTXn_e;

 
typedef enum
{
    PTA, PTB, PTC, PTD, PTE, PTF, PTG, PTH, PTI,

    PTX_MAX,
} PTX_e;

 
typedef enum
{
    PT0 , PT1 , PT2 , PT3 , PT4 , PT5 , PT6 , PT7 ,
} PTn_e;






 
typedef enum
{
    PULLUP_DISBLE ,     
    PULLUP_ENBLE ,     

} port_pullup_cfg;



extern void port_pull   (PTXn_e ptxn, char  cfg);
extern char port_hdrve  (PTXn_e ptxn, char  cfg);




 

 







 















 















                

 

                

 
                



 

                

 



                

 


                

 

                

 

                

 

                

 

                

 

                

 

                

 


                 















 















 





































































































 
typedef enum GPIO_CFG
{
    
    GPI         = 0,                                
    GPO         = 1,                                
} GPIO_CFG;


extern  GPIO_MemMapPtr      GPIOX[];



 

extern void    gpio_init  (PTXn_e, GPIO_CFG, uint8 data);    
extern void    gpio_ddr   (PTXn_e, GPIO_CFG);                
extern void    gpio_set   (PTXn_e,           uint8 data);    
extern void    gpio_turn  (PTXn_e);                          
extern uint8   gpio_get   (PTXn_e);                          





























 
















 


















 
















 


















 















 


 
 





 


typedef struct
{
    uint16_t    flag;                   
    uint16_t    ver;                    

    
    uint8_t    *ascii_6x12;             
    uint8_t    *ascii_8x16;             

    
    void       *sprintf;                
    void       *printf;                 
    void       *atoi;                   
    void       *itoa;                   
    void       *ftoa;                   
    void       *ftoan;                  

    
    void       *memcpy;                 
    void       *memset;                 
    void       *strlen;                 

    
    void       *flash_init;             
    void       *flash_erase_sector;     
    void       *flash_write;            
    void       *flash_write_buf;        
    

    
    void       *flash_data_init;        
    void       *flash_data_reset;       
    void       *flash_data_load;        
    void       *flash_data_save;        


    
    void       *spi_init;               
    void       *spi_set_baud;           
    void       *spi_mosi;               
    void       *spi_mosi_cmd;           

    
    void       *pwt_pulse_init;         
    
    void       *pwt_pulse_get;          

    
    void       *pwt_pulse_pos_get;      
    void       *pwt_pulse_neg_get;      

    
    void       *kbi_init;               
    void       *kbi_allinit;            

    
    void       *irq_init;               

    
    void       *ftm_timing_init;        

    
    void       *ftm_pulsing_init;               

    
    void       *jmp_app;                
    void       *jmp_bin;                


} mydata_in_t;









extern int core_clk_khz;
extern int core_clk_mhz;
extern int bus_clk_khz;
extern int timer_clk_khz;
















 



typedef FTM_Type    *FTMn_e;




typedef enum
{

    FTM_CH0,
    FTM_CH1,
    FTM_CH2,
    FTM_CH3,
    FTM_CH4,
    FTM_CH5,
    FTM_CH6,
    FTM_CH7,

} FTM_CHn_e;


typedef enum
{
    FTM_PS_1,
    FTM_PS_2,
    FTM_PS_4,
    FTM_PS_8,
    FTM_PS_16,
    FTM_PS_32,
    FTM_PS_64,
    FTM_PS_128,

    FTM_PS_MAX,
} FTM_PS_e;     

extern FTM_MemMapPtr FTMN[3];

 



extern void  ftm_pwm_init (FTMn_e, FTM_CHn_e, uint32 freq, uint32 duty);  
extern void  ftm_pwm_duty (FTMn_e, FTM_CHn_e,              uint32 duty);  


extern void  ftm_pwm_finit(FTMn_e, FTM_CHn_e, uint32 freq, float duty) ;
extern void  ftm_pwm_fduty(FTMn_e, FTM_CHn_e,              float duty);  

extern void  ftm_pwm_freq (FTMn_e,            uint32 freq);               


 

typedef enum
{
    FTM_Rising,               
    FTM_Falling,              
    FTM_Rising_or_Falling     
} FTM_Input_cfg;


extern void     ftm_input_init  (FTMn_e, FTM_CHn_e, FTM_Input_cfg, FTM_PS_e ps);    
extern uint16   ftm_input_get   (FTMn_e, FTM_CHn_e);                                
extern void     ftm_input_clean (FTMn_e );                                          

extern void     FTM1_Input_test_handler(void);                      


void ftm_enable_irq(FTMn_e ftmn);
void ftm_clear_overflag(FTMn_e ftmn);
void ftm_clean(FTMn_e ftmn);

void     ftm_pulse_init(FTMn_e ftmn, FTM_PS_e ps, PTXn_e tclk_ptxn);
uint16_t ftm_pulse_get(FTMn_e ftmn);

void    ftm_pulse_mux(FTMn_e ftmn, PTXn_e ptxn);












typedef     uint32_t               FLASH_WRITE_TYPE;       



typedef struct
{
    uint16_t    sectornum_start;            
    uint16_t    sectornum_end;              
    void      *data_addr;                   
    uint16_t    data_size;                  
    uint16_t    res1;                       
    uint32_t    res2[2];                    


} flash_data_t;




 
typedef enum
{
    
    SLAVE = (0 << 4),    
    MASTER = (1 << 4) ,  

    
    CPOL_CPHA_00  = (0 << 2) ,
    CPOL_CPHA_01  = (1 << 2) ,
    CPOL_CPHA_10  = (2 << 2) ,
    CPOL_CPHA_11  = (3 << 2) ,



} SPI_CFG;



 
typedef SPI_Type *SPIn_e ;





typedef enum
{
    PWT_IN0,
    PWT_IN1,

} PWT_INn_e;


typedef enum
{
    PWT_PS_1,
    PWT_PS_2,
    PWT_PS_4,
    PWT_PS_8,
    PWT_PS_16,
    PWT_PS_32,
    PWT_PS_64,
    PWT_PS_128,

    PWT_PS_MAX,
} PWT_PS_e;






typedef enum
{
    Pwt_Null                = 0,
    Pwt_Disable             = 1,                
    Pulse_Over_Enable_irq   = 0x10u | 0x40u   ,       
    Pulse_Width_Enable_irq  = 0x20u | 0x40u   ,      

    Cycle_Falling     = (((uint32_t)(((uint32_t)(0))<<11))&0x1800u)   ,  
    Cycle_Rising     = (((uint32_t)(((uint32_t)(3))<<11))&0x1800u)   ,  

    Duty_Rising      = (((uint32_t)(((uint32_t)(1))<<11))&0x1800u)   , 
    Duty_Falling      = (((uint32_t)(((uint32_t)(2))<<11))&0x1800u)   , 

} PWT_CFG_e;



typedef enum
{
    
    KBI_IRQ_DIS        = (0),   

    KBI_PULLUP_DIS  = (1 << 4),      
    KBI_PULLUP_EN   = (2 << 4),      

    KBI_FALLING     = (1 << 0),      
    KBI_RISING      = (2 << 0),      

    KBI_ZERO        = (1 << 2) ,     
    KBI_ONE         = (2 << 2)       


} KBI_CFG;


static KBI_MemMapPtr KBIn[] = { ((KBI_Type *)(0x40079000u)), ((KBI_Type *)(0x4007A000u)) };        









typedef enum
{
    
    IRQ_NULL        = (0),   

    IRQ_PULLUP_EN   = 0,                                                            
    IRQ_PULLUP_DIS  = (1 << 6),                                   

    IRQ_FALLING     = (0),                                                          
    IRQ_RISING      = (1 << 5),                                   

    IRQ_ZERO        = (0 | (1 << 0) ) ,                           
    IRQ_ONE         = ((1 << 5) | (1 << 0) )    


} IRQ_CFG;






typedef int       (*sprintf_t)         (char *buf, const char *fmt, ...) ;



extern int enter_fputc(char ch);                    
typedef int fputc_t (char c);
typedef int (*printf_t)(fputc_t *fp, const char *fmt, ...);



typedef int       (*atoi_t)            (char *str);



typedef char *    (*itoa_t)            (int n, char *chBuffer);



typedef char *    (*ftoa_t)            (double dValue, char *chBuffer);



typedef char *    (*ftoan_t)            (double dValue, char *chBuffer, int ndigits);





typedef void *    (*memcpy_t)  ( uint8_t *dst, uint8_t *src, uint32_t count);



typedef void *    (*memset_t)  (void *src, int c, int count);



typedef int       (*strlen_t)(const char *str);





typedef void      (*flash_init_t)          (int);



typedef uint8_t   (*flash_erase_sector_t)  (uint16_t sectorNum);



typedef uint8_t   (*flash_write_t)         (uint16_t sectorNum, uint16_t offset, FLASH_WRITE_TYPE data);



typedef uint8_t   (*flash_write_buf_t)     (uint16_t sectorNum, uint16_t offset, uint16_t cnt, uint8 buf[]);





typedef void      (*flash_data_init_t)     (flash_data_t *d, int bus_khz);



typedef void      (*flash_data_reset_t)    (flash_data_t *d);



typedef uint8_t   (*flash_data_load_t)     (flash_data_t *d);



typedef uint8_t   (*flash_data_save_t)     (flash_data_t *d);






typedef uint32_t  (*spi_init_t)       (SPIn_e spi, PTXn_e pcs, SPI_CFG, uint32 baud, uint32 bus_khz, char use_pin_mode);


typedef uint32_t  (*spi_set_baud_t)   (SPIn_e spi,                     uint32 baud, uint32 bus_khz);



typedef void (*spi_mosi_t)       (SPIn_e, PTXn_e pcs,                              uint8 *modata, uint8 *midata,               uint32 len);



typedef void (*spi_mosi_cmd_t)   (SPIn_e, PTXn_e pcs, uint8 *mocmd , uint8 *micmd , uint8 *modata, uint8 *midata, uint32 cmdlen , uint32 len);




typedef void     (*pwt_pulse_init_t)     (PWT_INn_e INn,  uint32_t cfg);



typedef uint16_t (*pwt_pulse_get_t)     (PWT_INn_e INn);





typedef uint16_t (*pwt_pulse_pos_get_t)(PWT_INn_e INn);



typedef uint16_t (*pwt_pulse_neg_get_t)(PWT_INn_e INn);





typedef void (*kbi_init_t) (PTXn_e ch, uint8_t cfg);



typedef void (*kbi_allinit_t) (uint64_t ch_mask, uint8_t cfg);





typedef void (*irq_init_t)  (PTXn_e, uint8_t cfg);





typedef void (*ftm_timing_init_t)(FTMn_e ftmn, uint16_t counttime, FTM_PS_e ps);





typedef void (*ftm_pulsing_init_t)(FTMn_e ftmn, uint16_t counttime, FTM_PS_e ps, PTXn_e tclk_ptxn);





typedef void      (*jmp_app_t)             (uint32_t sp, uint32_t pc);



typedef void      (*jmp_bin_t)             (uint32_t addr);


























 


extern unsigned char vcan_str[4*16*2];












extern void LCD_Char_CH (Site_t site, const uint8 *str, uint16 Color, uint16 bkColor);
extern void LCD_Str_CH  (Site_t site, const uint8 *str, uint16 Color , uint16 bkColor); 
extern void LCD_Str_ENCH(Site_t site, const uint8 *str  , uint16 Color , uint16 bkColor); 


extern void LCD_FChar_CH (Site_t site, const uint8 *strbuf,             uint16 Color, uint16 bkColor);
extern void LCD_FStr_CH  (Site_t site, const uint8 *strbuf, uint16 num,  uint16 Color, uint16 bkColor);










 






































 

void lcd_init(void);                                                                                    

 

extern void lcd_point          (Site_t,                                        uint16 rgb565);                 
extern void lcd_points         (Site_t *site,  uint32 point_num,               uint16 rgb565);                 
extern void lcd_rectangle      (Site_t, Size_t,                                uint16 rgb565);                 
extern void lcd_char           (Site_t,        uint8 ascii,                    uint16 Color, uint16 bkColor);  
extern void lcd_str            (Site_t,        uint8 *Str,                     uint16 Color, uint16 bkColor);  

extern void lcd_cross          (Site_t, uint16 len,                              uint16 rgb565);                

extern void lcd_clear          (uint16 rgb565);     


extern void lcd_num            (Site_t,        uint32 num,                     uint16 Color, uint16 bkColor);  
extern void lcd_num_bc         (Site_t,        uint32 num, uint8 max_num_bit,  uint16 Color, uint16 bkColor);  

extern void lcd_img_gray       (Site_t site, Size_t size, uint8 *img);                   
extern void lcd_img_gray_z     (Site_t site, Size_t size, uint8 *img, Size_t imgsize);   

extern void lcd_img_binary     (Site_t site, Size_t size, uint8 *img);                   
extern void lcd_img_binary_z   (Site_t site, Size_t size, uint8 *img, Size_t imgsize);   

extern void lcd_wave(Site_t site, Size_t size, uint8 *img, uint8 maxval, uint16 Color , uint16 bkColor); 
extern void lcd_wave_display(Site_t site, Size_t size, uint8 *img, uint8 maxval, uint16 Color);    






 











 






extern void     LCD_ST7735S_init();
extern void     LCD_ST7735S_dir(uint8 option);
extern void     LCD_ST7735S_ptlon(Site_t site, Size_t size);
extern uint16   ST7735S_get_h();
extern uint16   ST7735S_get_w();
extern uint8    ST7735S_get_dir();


extern void LCD_ST7735S_wr_data(uint8 data);
extern void LCD_ST7735S_wr_cmd(uint8 cmd);























 


extern unsigned char vcan_str[4*16*2];













 






































 

void lcd_init(void);                                                                                    

 

extern void lcd_point          (Site_t,                                        uint16 rgb565);                 
extern void lcd_points         (Site_t *site,  uint32 point_num,               uint16 rgb565);                 
extern void lcd_rectangle      (Site_t, Size_t,                                uint16 rgb565);                 
extern void lcd_char           (Site_t,        uint8 ascii,                    uint16 Color, uint16 bkColor);  
extern void lcd_str            (Site_t,        uint8 *Str,                     uint16 Color, uint16 bkColor);  

extern void lcd_cross          (Site_t, uint16 len,                              uint16 rgb565);                

extern void lcd_clear          (uint16 rgb565);     


extern void lcd_num            (Site_t,        uint32 num,                     uint16 Color, uint16 bkColor);  
extern void lcd_num_bc         (Site_t,        uint32 num, uint8 max_num_bit,  uint16 Color, uint16 bkColor);  

extern void lcd_img_gray       (Site_t site, Size_t size, uint8 *img);                   
extern void lcd_img_gray_z     (Site_t site, Size_t size, uint8 *img, Size_t imgsize);   

extern void lcd_img_binary     (Site_t site, Size_t size, uint8 *img);                   
extern void lcd_img_binary_z   (Site_t site, Size_t size, uint8 *img, Size_t imgsize);   

extern void lcd_wave(Site_t site, Size_t size, uint8 *img, uint8 maxval, uint16 Color , uint16 bkColor); 
extern void lcd_wave_display(Site_t site, Size_t size, uint8 *img, uint8 maxval, uint16 Color);    






 






extern void     LCD_ST7735R_init();
extern void     LCD_ST7735R_dir(uint8 option);
extern void     LCD_ST7735R_ptlon(Site_t site, Size_t size);
extern uint16   ST7735R_get_h();
extern uint16   ST7735R_get_w();
extern uint8    ST7735R_get_dir();


extern void LCD_ST7735R_wr_data(uint8 data);
extern void LCD_ST7735R_wr_cmd(uint8 cmd);

















uint16  st7735r_h   = 128;
uint16  st7735r_w   = 128;
uint8   st7735r_dir = 0;

void LCD_ST7735R_wr_data(uint8 data)
{
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3)) = 1;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2)) = 1;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4)) = 0;

    (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2]) = data;

    ;

    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5)) = 0;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5)) = 1;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4)) = 1;
}

void LCD_ST7735R_wr_cmd(uint8 cmd)
{
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3)) = 1;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2)) = 0;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4)) = 0;

    (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2]) = cmd;

    ;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5)) = 0;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5)) = 1;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4)) = 1;
}




 
void    LCD_ST7735R_init()
{
    uint8 n ;

    for(n = 0; n < 8; n++)
    {
        gpio_init  ((PTXn_e)(PTG0 + n), GPO, 0);
    }


    gpio_init  (PTI5, GPO, 0);
    gpio_init  (PTI3, GPO, 1);
    gpio_init  (PTI4, GPO, 1);
    gpio_init  (PTI2, GPO, 0);
    gpio_init  (PTI6, GPO, 0);


    
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b6)) = 0;
    ;
    ((((Dtype *)(&(GPIOX[2]->PDOR )))->b6)) = 1;
    soft_delay_ms(500);      

    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x11); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);           
    soft_delay_ms(120);      
    
     
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xB1); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);     
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x05); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);    
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);    
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);    
    
    

     
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xB2); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);     
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x05); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

     
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xB3); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x05); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x05); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

    
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xB4); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);   

    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x07); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);  
    
    

    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xC0); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);   
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x28); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x08); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x84); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xC1); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0XC0); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xC2); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x0C); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xC3); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x8C); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xC4); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x8A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xEE); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xC5); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);   
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x0C); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0); 
    
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xE0); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x05); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x1A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x0C); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x0E); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x34); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2D); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2F); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2D); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2F); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3C); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x01); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x02); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x10); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xE1); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x04); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x1B); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x0D); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x0E); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2D); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x29); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x24); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x29); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x28); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x26); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x31); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3B); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x03); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x12); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    

    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x3A); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0); 
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x05); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x29); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0); 
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2c); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0); 

    LCD_ST7735R_dir(st7735r_dir);

}





 
void LCD_ST7735R_dir(uint8 option)
{
    if (!(option < 4)) assert_failed("C:\\Users\\ZHY\\Desktop\\31.FLASH_\261\344\301\277\266\301\320\264\241\276\315\306\274\366\241\277\\Board\\src\\VCAN_LCD_ST7735R.c", 196);

    st7735r_dir = option;
    switch(option)
    {
    case 0:
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x36); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0); 
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xc8); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2a); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(128); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2B); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(50); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(128 + 50); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        st7735r_h   = 128;
        st7735r_w   = 128;
        break;
    case 1:
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x36); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0); 
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0xA8); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2a); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x03); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x82); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2B); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x02); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x81); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        st7735r_h   = 128;
        st7735r_w   = 128;
        break;
    case 2:
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x36); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0); 
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x08); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2a); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x02); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x81); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2B); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x03); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x82); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        st7735r_h   = 128;
        st7735r_w   = 128;
        break;
    case 3:
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x36); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0); 
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x68); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2a); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x03); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x82); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2B); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x00); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
        do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(128); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

        st7735r_h   = 128;
        st7735r_w   = 128;
        break;
    default:
        break;
    }

}






 
void LCD_ST7735R_ptlon(Site_t site, Size_t size)
{

    if(st7735r_dir & 0x01)
    {
        site.x += 32;     
        
    }
    else
    {
        
        site.y += 32;
    }

    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2a); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);   
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)((uint8)(site . x >> 8)); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0); 
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)((uint8)site . x); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);   
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)((uint8)((site . x + size . W - 1) >> 8)); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)((uint8)(site . x + size . W - 1)); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)(0x2B); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)((uint8)(site . y >> 8)); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)((uint8)site . y); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)((uint8)((site . y + size . H - 1) >> 8)); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);
    do { ((((Dtype *)(&(GPIOX[2]->PDOR )))->b3))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b2))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=0; (((Dtype *)(&(GPIOX[1]->PDOR )))->B[2])=(uint8)((uint8)(site . y + size . H - 1)); ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=0; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b5))=1; ((((Dtype *)(&(GPIOX[2]->PDOR )))->b4))=1; }while(0);

}





 
uint16 ST7735R_get_h()
{
    return st7735r_h;
}





 
uint16 ST7735R_get_w()
{
    return st7735r_w;
}





 
uint8 ST7735R_get_dir()
{
    return st7735r_dir;
}




