/*
 * main.c
 *  Created on: 2019-11-20
 *  Author: Anthony Shivakumar
 * Description: This is a simple example of how to use Emscripten to compile C/C++ code to JavaScript.
 *             This example draws a circle on a canvas.
 *            To compile this example, run the following command:
 *            emcc main.c       
*/
#include <emscripten/emscripten.h>

EM_JS(void, drawCircle, (int x, int y, int r), {
    var canvas = document.getElementById("canvas");
    var ctx = canvas.getContext("2d");
    ctx.fillStyle = "#FF0000";
    ctx.strokeStyle = "#000000";
    ctx.lineWidth = 4;
    ctx.beginPath();
    ctx.arc(x, y, r, 0, 2 * Math.PI);
    ctx.fill();
    ctx.stroke();
});

int main() {
    drawCircle(80, 80, 50);
    return 0;
}
~