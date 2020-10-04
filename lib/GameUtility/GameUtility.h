typedef struct {
    // I'm going to say x, y, is in the center
    int x;
    int y;
    int width;
    int height;
} Rect;

Rect newRect(int x, int y, int w, int h) {
    Rect r = {x, y, w, h};
    return r;
}

int rectsCollide(Rect *r1, Rect *r2) {
    if (r1->x + r1->width/2 < r2->x - r2->width/2) return 0;
    if (r1->x - r1->width/2 > r2->x + r2->width/2) return 0;
    if (r1->y + r1->height/2 < r2->y - r2->height/2) return 0;
    if (r1->y - r1->height/2 > r2->y + r2->height/2) return 0;
    return 1;
}

