// rastertri  L A  ax ay  bx by  cx cy
// L: largura em pixels da imagem a ser gerada;
// A: altura em pixels da imagem a ser gerada;
// ax e ay: coordenadas Cartesianas inteiras (em pixels) da localização do primeiro vértice do triângulo;
// bx e by: coordenadas Cartesianas inteiras (em pixels) da localização do segundo vértice do triângulo;
// cx e cy: coordenadas Cartesianas inteiras (em pixels) da localização do terceiro vértice do triângulo.

#include <stdio.h>
#include <stdlib.h>

int fab(int x, int y);
int fbc(int x, int y);
int fca(int x, int y);

int A1, B1, C1, A2, B2, C2, A3, B3, C3;
int width, height, ax, ay, bx, by, cx, cy;
int alpha, beta, gama;

int main(int argc, char *argv[]) {

  if (argc != 9) {
    printf("Invalid number of parameters!\n");
    return 1;
  }
  width = atoi(argv[1]);
  height = atoi(argv[2]);
  ax = atoi(argv[3]);
  ay = atoi(argv[4]);
  bx = atoi(argv[5]);
  by = atoi(argv[6]);
  cx = atoi(argv[7]);
  cy = atoi(argv[8]);

  int vec1x = bx - ax;
  int vec1y = by - ay;
  A1 = vec1y;
  B1 = -vec1x;
  C1 = -vec1y * ax + vec1x * ay;

  if (fab(cx, cy) < 0) {
    // swap between points a and b
    int aux = ax;
    ax = bx;
    bx = aux;
    aux = ay;
    ay = by;
    by = aux;

    vec1x = bx - ax;
    vec1y = by - ay;
    A1 = vec1y;
    B1 = -vec1x;
    C1 = -vec1y * ax + vec1x * ay;
  }

  int vec2x = cx - bx;
  int vec2y = cy - by;
  A2 = vec2y;
  B2 = -vec2x;
  C2 = -vec2y * bx + vec2x * by;

  int vec3x = ax - cx;
  int vec3y = ay - cy;
  A3 = vec3y;
  B3 = -vec3x;
  C3 = -vec3y * cx + vec3x * cy;

  int x, y;
  for(y = height; y >= 1; y--) {
    for(x = 1; x <= width; x++) {
      alpha = fbc(x, y);
      beta = fca(x, y);
      gama = fab(x, y);
      //printf("%d %d %d x: %d y: %d\n", alpha, beta, gama, x, y);

      if (alpha >= 0 && beta >= 0 && gama >= 0)
        printf("0 ");
      else
        printf("1 ");
    }
    printf("\n");
  }
}

int fab(int x, int y) {
  return A1*x + B1*y + C1;
}

int fbc(int x, int y) {
  return A2*x + B2*y + C2;
}

int fca(int x, int y) {
  return A3*x + B3*y + C3;
}
