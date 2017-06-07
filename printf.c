#include <stdarg.h>
#include "printf.h"
#include "uart.h"

void printf_init() {
  uart_init();
}

int unsigned_to_base(char *buf, int n, unsigned int val, int base, int width) {
	int size = 2;
    unsigned int base1 = (unsigned int)base;
	unsigned int baseMultiplyer = (unsigned int)base1;
    while (val / baseMultiplyer >= base1){
        size ++;
        baseMultiplyer *= (unsigned int)base1;
    }
    if (val / base == 0){
        size = 1;
        baseMultiplyer = 1;
    }
    
  if (n != 0){
		//baseMultiplyer /= (unsigned int)base1;
		int counter = 1;
        int zeros = width - size;// - 1;
		while (counter < n && baseMultiplyer != 0){
			if (zeros > 0){
				*buf = '0';
				buf++;
				zeros --;
			}
			else{
				if (val / baseMultiplyer > 9){
					*buf = 'a' + (val / baseMultiplyer) - 10;
				}else{
					*buf = '0' + (val / baseMultiplyer);
				}
				buf++;
				val = val % baseMultiplyer;
				baseMultiplyer = baseMultiplyer / (unsigned int)base1;
			}
			counter ++;
		}
		*buf = '\0';
	}
	if (size > width){
        return size;
	}
	return width;
}

int signed_to_base(char *buf, int n, int val, int base, int width) {
    if (val < 0){
        if (n == 0 || n == 1){
            return 1 + unsigned_to_base(buf, n, 0 - val, base, width - 1);
        }
        *buf = '-';
        buf++;
		return 1 + unsigned_to_base(buf, n - 1, 0 - val, base, width - 1);
    }
    else if (n == 0 || n == 1){
        return unsigned_to_base(buf, n, val, base, width);
    }
    return unsigned_to_base(buf, n, val, base, width);
}

int vsnprintf(char *s, int n, const char *format, va_list args) {
  int count = 0;
  while(*format != '\0'){
		if (*format != '%'){
			*s = *format;
			s++;
			format++;
			count++;
		}
		else{
			format++;
			int width = 0;
			while (*format >= '0' && *format <= '9'){
        width *= 10;
        width += *format - '0';
        format++;
			 }
			if (*format == 'd'){
				int num = va_arg(args, int);
				int length = signed_to_base(s, n - count, num, 10, width);
				s += length;
				count += length;
			}
			else if (*format == 'x'){
				int num = va_arg(args, int);
				int length = signed_to_base(s, n - count, num, 16, width);
				s += length;
				count += length;
			}
			else if (*format == 'b'){
				int num = va_arg(args, int);
				int length = signed_to_base(s, n - count, num, 2, width);
				s += length;
				count += length;
			}
			else if (*format == 'c'){
				char letter = (char)va_arg(args, int);
				*s = letter;
				s++;
				count ++;
			}
			else if(*format == 's'){
				char *letter = va_arg(args, char*);
				while (*letter != '\0'){
					*s = *letter;
					s++;
					letter++;
					count ++;
				}
			}
			format ++;
		}
  }
	*s = *format;
	return count;
}

int snprintf(char *s, int n, const char *format, ...) {
	va_list args;
	va_start(args, format);
	int count = vsnprintf(s, n, format, args);
	va_end(args);
	return count;
}

int printf(const char *format, ...) {
	char myArray [1000];
	va_list args;
	va_start(args, format);
	int count = vsnprintf(myArray, 1000, format, args);
	for (int i = 0; i < count; i ++){
  	uart_putc(myArray[i]);
  }
  va_end(args);
  return count;
}
