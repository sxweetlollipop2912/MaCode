SET filename=sinhnhat
SET inp=i
SET out=o
SET start=0
SET end=9
for /L %%g in (%start%,1,%end%) do (
	md test%%g
	copy %filename%.%inp%%%g test%%g
	rename test%%g\%filename%.%inp%%%g %filename%.inp
	copy %filename%.%out%%%g test%%g
	rename test%%g\%filename%.%out%%%g %filename%.out
)
pause



