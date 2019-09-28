#ifndef __GLOBALS_H_
#define __GLOBALS_H_

// Deletes a buffer
#define RELEASE( x ) \
    {\
       if( x != nullptr )\
       {\
         delete x;\
	     x = nullptr;\
       }\
    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
	{\
       if( x != nullptr )\
       {\
           delete[] x;\
	       x = nullptr;\
		 }\
	 }

inline unsigned char GET_BIT(unsigned char b, unsigned char v){
	return 0x01 << b & v;
}

inline unsigned char GET_2BIT(unsigned char b, unsigned char v) {
	return 0x03 << b & v;
}
#endif