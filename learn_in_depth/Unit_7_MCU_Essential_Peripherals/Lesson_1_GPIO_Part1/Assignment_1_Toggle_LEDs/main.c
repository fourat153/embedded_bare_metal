typedef volatile unsigned char vuint8_t;
typedef unsigned int uint32_t;

// GPIO
#define GPIO_BASE   0x20
#define DDRC        (*(vuint8_t *)(GPIO_BASE + 0x14))
#define PORTC       (*(vuint8_t *)(GPIO_BASE + 0x15))

// GPIO pins
#define PC0     0
#define PC1     1
#define PC2     2
#define PC3     3

// Hardware pins
#define LED0    PC0
#define LED1    PC1
#define LED2    PC2
#define BUZZER  PC3

// Utilities 
#define SET_BIT(reg, bit)   (reg |= (1<<bit))
#define CLR_BIT(reg, bit)   (reg &= ~(1 << (bit)))

// Prototypes
void delay(uint32_t count);

int main(void)
{
    // Initialize Port C pins 
    DDRC |= (1 << LED0)|(1 << LED1)|(1 << LED2)|(1 << BUZZER);
    
    while (1)
    {
   
        CLR_BIT(PORTC, BUZZER);     // Clear BUZZER
        CLR_BIT(PORTC, LED2);       // Clear LED2
        CLR_BIT(PORTC, LED1);       // Clear LED1
        SET_BIT(PORTC, LED0);       // Set LED0
        delay(1000);
        
        CLR_BIT(PORTC, LED0);       // Clear LED0
        SET_BIT(PORTC, LED1);       // Set LED1
        delay(1000);     

        CLR_BIT(PORTC, LED1);       // Clear LED1
        SET_BIT(PORTC, LED2);       // Set LED2
        delay(1000);
        
        SET_BIT(PORTC, BUZZER);     // Set BUZZER
        delay(1000);
    }
    return 0;
}


void delay(uint32_t count)
{
    uint32_t i, j;
    
    for(i = 0; i < delay; i++)
    {
        for (j = 0; j < 255; j++);
    }
}