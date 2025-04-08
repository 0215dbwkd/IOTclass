configuration BlinkAppC
{
}
implementaion
{
	components MainC, BlinkC, LedsC;
	components new TimerMillic() as Timer0;
	
	BlinkC -> MainC.Boot;
	
	BlinkC.Time0 -> Timer0;
	BlinkC.Leds -> LedsC;
}
