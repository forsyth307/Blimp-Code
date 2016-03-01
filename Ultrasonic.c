
task main(){
sensorType(s1)=sensorSonar;
sensorType(s2)=sensorSonar;


//code

checkWall(threshold);

}

task checkWall(threshold){
	if (sensorValue(s1)<=threshold){
		float dist=sensorValue(s1);
		motor(motorA)=-100; //full reverse
		motor(motorB)=-100;
		deflect_rudder(-45); //pseudocode, we should have a rudder and elevator function
		wait1msc(200);
		if (sensorValue(s1)>dist)//check to make sure that we are turning away from wall
			deflect_rudder(45)
		return true;
else return false;
}

task land(){
	motor(motorA)=0;
	motor(motorB)=0;
	deflect_elevator(-45);//angle elevators to descend
	wait1msc(3000);
	deflect_elevator(45); 
	while (sensorValue(s2)<30){}
	deflectElevator(30);//level out
	motor(motorA)=-30;
	motor(motorB)=-30; // slow down
	wait1msc(500);
	deflectElevator(0);
	while sensorValue(s2)>=20{}
	displayString(0,"Landed!");
}
