 //Le Trong Tung
//in c++
    cin >> n;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin >> a[i][j];
    //Prefix sum 2d
    f[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
        f[0][i] = f[0][i - 1] + a[0][i];

    for (int i = 0; i < n; i++)
        f[i][0] = f[i - 1][0] + a[i][0];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            f[i][j]= f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
