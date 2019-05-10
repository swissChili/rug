# rug

a c++ raycasting engine powered by SFML

### what's raycasting

1. for every pixel column on the screen, find the closest wall in front of it
  by casting a ray outwards
2. figure out how far away it is
3. draw that column on the screen with the appropriate size
4. ???
5. profit

### building

```sh
$ meson build
$ cd build
$ ninja
```
