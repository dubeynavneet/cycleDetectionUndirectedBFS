bool reachDestination(int sx, int sy, int dx, int dy) {
    while(sx<dx && sy<dy){
        if(dx>dy){
            dx%=dy;
        }
        else{
            dy%=dx;
        }
    }
    if(sx==dx && sy<=dy){
        return (dy-sy)%dx==0;
    }
    if(sy==dy && sx<=dx){
        return (dx-sx)%dy==0;
    }
    return fals
}
