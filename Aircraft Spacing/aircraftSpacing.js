const dpCalculator = function (arrFlight) {
    const flightCount = arrFlight.length;
    const dpMaxArr = [];
    dpMaxArr[0] = arrFlight[0];
    dpMaxArr[1] = Math.max(arrFlight[0], arrFlight[1]);
    for(let i = 2; i < flightCount; i++) {
        dpMaxArr[i] = Math.max((dpMaxArr[i - 2] + arrFlight[i]), dpMaxArr[i - 1]);
    }
    return dpMaxArr[flightCount- 1];
}

const dpAns = dpCalculator([155, 55, 2, 96, 67, 203, 3]);

console.log(dpAns);
