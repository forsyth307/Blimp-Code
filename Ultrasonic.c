
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
		rudder.move(-45); //pseudocode, we should have a rudder and elevator_object
		wait1msc(200);
		if (sensorValue(s1)>dist)//check to make sure that we are turning away from wall
			rudder.move(45)

		return true;
else return false;
}

task land(){
	motor(motorA)=0;
	motor(motorB)=0;
	elevator.move(-45);//angle elevators to descend
	wait1msc(3000);
	elevator.move(0);
	while (sensorValue(s2)<30){}
	elevator.move(30)//level out
	motor(motorA)=-30;
	motor(motorB)=-30; // slow down
	wait1msc(500);
	elevator.move(0);
	while sensorValue(s2)>=20{}
	displayString(0,"Landed!");
}

