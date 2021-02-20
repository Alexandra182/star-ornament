#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN1 PB0 // White LEDs
#define LED_PIN2 PB1 // Blue/Purple LEDs

int main (void) {
  /* setup */
  DDRB  = 0b00000011;  // set LED pins as OUTPUT

  TCCR0A |= (1 << COM0B1) | (1 << COM0A1); // Clear OC0B and OC0A on Compare Match
  TCCR0A |= (1 << WGM01) | (1 << WGM00);   // set fast PWM Mode
  TCCR0B |= (1 << CS00);                   // No clk prescaling

  OCR0B = 0; // Initialise LEDs as off
  OCR0A = 0;

  while (1) {
    for (int fadeValue = 0 ; fadeValue <= 150; fadeValue += 5) {
      OCR0B = fadeValue;
      OCR0A = 150 - fadeValue;
      _delay_ms(50);
    }

    for (int fadeValue = 150 ; fadeValue >= 0; fadeValue -= 5) {
      OCR0B = fadeValue;
      OCR0A = 150 - fadeValue;
      _delay_ms(50);
    }
  }
  _delay_ms(500);
}
