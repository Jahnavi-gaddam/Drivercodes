extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern void uart0_tx_string(const char *ptr);
extern unsigned char uart0_rx(void);



extern void delay_sec(unsigned int sec);
extern void delay_ms(unsigned int ms);


extern void lcd_cmd(unsigned char cmd);
extern void lcd_data(unsigned char data);
extern void lcd_init(void);


extern void uart0_tx_binary(int num);
extern void uart0_tx_hexa(int num);
extern void uart0_tx_octal(int num);
extern void uart0_tx_integer(int num);
extern void uart0_tx_float(float f);

extern void uart0_isr(void)__irq;
extern void config_vic_for_uart0(void);
extern void config_uart0_intr(void);
extern void adc_init(void);
extern unsigned int adc_read(unsigned char ch_num);
