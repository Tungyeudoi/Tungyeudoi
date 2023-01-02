 
//minimun
while(l < r){
        int mid = (l + r)/2;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }

//maximum
while(l <= r){
        int mid = l + (r + l - 1)/2;
        if(check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }



