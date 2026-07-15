typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
typedef signed  int s32;

extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);

extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);

extern void adc_init(void);
extern unsigned int adc_read(unsigned char ch_num);

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);

extern void uart0_tx_integer(int num);
extern void uart0_tx_float(float f);
extern void uart0_tx_string(char *ptr);

extern void config_vic_for_uart0_string(void);
extern void uart0_init(unsigned int baud);
extern void config_uart0(void);


