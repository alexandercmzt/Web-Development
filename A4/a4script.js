var state, ctx;
state = "resetted"
ctx = document.getElementById("canvas").getContext("2d");

function rotatePic() {
	if (state == "house") {
		drawSun();
		state = "sun";
	}
	else if (state == "sun") {
		drawReset();
		state = "resetted";
	}
	else if (state == "resetted") {
		drawHouse();
		state = "house";
	}
}

function drawHouse() {
	ctx.beginPath();
	ctx.moveTo(25,275);
	ctx.lineTo(25,200);
	ctx.moveTo(75,275);
	ctx.lineTo(75,200);
	ctx.moveTo(25,275);
	ctx.lineTo(75,275);
	ctx.moveTo(15,200);
	ctx.lineTo(85,200);
	ctx.moveTo(15,200);
	ctx.lineTo(50,180);
	ctx.moveTo(50,180);
	ctx.lineTo(85,200);
	ctx.stroke();
}

function drawSun() {
	ctx.beginPath();
	ctx.moveTo(300,75);
	ctx.beginPath();
	ctx.arc(300,75,40,0,2*Math.PI);
	ctx.stroke();
	ctx.moveTo(300,115);
	ctx.lineTo(300,145);
	ctx.moveTo(340,75);
	ctx.lineTo(370,75);
	ctx.moveTo(260,75);
	ctx.lineTo(230,75);
	ctx.moveTo(334,95);
	ctx.lineTo(360,120);
	ctx.moveTo(270,100);
	ctx.lineTo(250,120);
	ctx.moveTo(270,47);
	ctx.lineTo(250,27);
	ctx.moveTo(327,47);
	ctx.lineTo(347,27);
	ctx.stroke();
}

function drawReset() {
	ctx.clearRect(0, 0, 400, 300);
}