#include <iostream>

using namespace std;

int map[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 0, 1, 0,
  0, 0, 0, 0, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
};

int& getElement(int *map, int width, int height, int x, int y)
{
  static int val = 0;
  
  if (x >= 0 && x < width && y >= 0 && y < height)
  {
    return map[x + y * width];
  }
  
  return val;
}

void markOffIslandElements(int *map, int width, int height, int x, int y)
{
  int& elem = getElement(map, width, height, x, y);
  
  if (elem == 1)
  {
    elem = 3;
  }
  else
  {
    return;
  }
  
  markOffIslandElements(map, width, height, x + 1, y);
  markOffIslandElements(map, width, height, x - 1, y);
  markOffIslandElements(map, width, height, x, y + 1);
  markOffIslandElements(map, width, height, x, y - 1);
}

int countIslands(int *map, int width, int height)
{
  int islands = 0;

  for (int x = 0; x < width; ++x)
  {
    for (int y = 0; y < height; ++y)
    {
      if (getElement(map, width, height, x, y) == 1)
      {
        islands++;
        markOffIslandElements(map, width, height, x, y);
      }
      map[x + y * width] = 3;
    }
  }
  
  return islands;
}

int main() {
	cout << "Number of Islands: " << countIslands(map, 8, 8) << endl;
	return 0;
}


