pro idlplot
 
 dim = 400

 xmin = -1.0
 xmax = 1.0
 ymin = 0
 ymax = 20
 zmax = 0.02

 level1 = 3
 level2 = 4
 level3 = 5

 color = 1

 openu,1,"dens.idl"
 a=assoc(1,bytarr(dim,dim,/nozero))
 dens=a(0)
 openu,2,"scale.idl"
 b=assoc(2,bytarr(30,256,/nozero))
 sca=b(0)
 d=size(dens) 
 s=size(sca) 

 for i=0, dim-1 do begin
	for j=0, dim-1 do begin
		if (dens(i,j) eq 0) then dens(i,j)=1
	endfor
 endfor

 if ( color eq 0 ) then begin
	 max  = 255
	 expo =	2
	 r = findgen(max+1)
	 g = findgen(max+1)
	 for i=0, max do begin
	     g(i) = max * ( 1 - r(i)/max ) ^ expo 
	 endfor
	 tvlct, g, g, g
	 black = 255
	 white = 0
	 ccol_1  = black
	 ccol_2  = black
	 ccol_3  = black
 endif else begin
	 loadct,4
	 max  = 255
	 r = findgen(max+1)
	 g = findgen(max+1)
	 b = findgen(max+1)

	 tvlct, r, g, b, /get
 	 r(0) = 255
	 g(0) = 255
	 b(0) = 255
	 tvlct, r, g, b

	 black = 1
	 white = 0
	 ccol_1 = black
	 ccol_2 = black
	 ccol_3 = black
 endelse

 set_plot,"x"
 window,1,xpos=850-dim,ypos=28,xsize=dim+400,ysize=dim+200,title="PIC - density"
 xoff=200
 yoff=100
 dist=100
 tv,dens,xoff,yoff
 x = xmin + (xmax-xmin)/d(1)*findgen(d(1))
 y = ymin + (ymax-ymin)/d(2)*findgen(d(2))
 zcrit = 256/zmax
 contour, dens, /noerase, xstyle = 4, ystyle = 4, $
	  level = [level1*zcrit,level2*zcrit,level3*zcrit], $
          c_color = [ccol_1,ccol_2,ccol_3],$
          position = [xoff,yoff,xoff+d(1),yoff+d(2)], $
          /device
 plot, x, y, xstyle = 1, xrange = [xmin,xmax], xtitle = "!3x/!7k!3!D0!3", $
          ystyle = 1, yrange = [ymin,ymax], ytitle="!3t/!7s!3", $
          charsize = 2,$
          color = black, /nodata, /noerase, /device,$
          position = [xoff,yoff,xoff+d(1),yoff+d(2)]

 xoff = xoff+d(1)+dist
 tv,sca,xoff,yoff
 x = 1.0/s(1)*findgen(s(1))
 y = zmax/s(2)*findgen(s(2))
 contour, sca, /noerase, xstyle = 4, ystyle = 1, yrange = [0,zmax],$
        ytitle = "!3n/n!Dc!3", charsize = 2, $
	levels = [level1, level2, level3], $
        c_color = [ccol_1,ccol_2,ccol_3], color = black, $	
        position = [xoff,yoff,xoff+s(1),yoff+s(2)], $
        /device

 close,1
 close,2

end


