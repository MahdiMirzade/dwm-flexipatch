void
togglefakefullscreen(const Arg *arg)
{
    Client *c = selmon->sel;
    if (!c)
        return;

    if (c->fakefullscreen) {
        if (c->isfullscreen)
            c->fakefullscreen = 0;
        else
            c->isfullscreen = 0;
    } else {
        if (c->isfullscreen) {
            c->isfloating = c->oldstate;
            c->bw = c->oldbw;
            c->x = c->oldx;
            c->y = c->oldy;
            c->w = c->oldw;
            c->h = c->oldh;
            resizeclient(c, c->x, c->y, c->w, c->h);
        }
        c->fakefullscreen = 1;
        c->isfullscreen = 0;
    }
    setfullscreen(c, !c->isfullscreen);
}