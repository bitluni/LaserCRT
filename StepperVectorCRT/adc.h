void readADCs()
{
 /* ADMUX = bit(REFS1) | bit(REFS0) | 6; 
  ADCSRA = bit(ADEN) | bit(ADSC) | bit(ADPS1); //| bit(ADPS1)| bit(ADPS2);
  while(!(ADCSRA & bit(ADSC)));
  int a6 = ADCL;
  a6 |= int(ADCH) << 8;
  ADMUX = bit(REFS1) | bit(REFS0) | 7; 
  ADCSRA = bit(ADEN) | bit(ADSC) | bit(ADPS1); //| bit(ADPS1)| bit(ADPS2);
  while(!(ADCSRA & bit(ADSC)));
  int a7 = ADCL;
  a7 |= int(ADCH) << 8;*/
  ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2));
  ADCSRA |= bit (ADPS2);
  int a6 = analogRead(A6);
  int a7 = analogRead(A7);
}