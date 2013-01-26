#!/usr/bin/python
# -*- coding: utf-8 -*-

from ttk import Frame, Button, Style
from Tkinter import Tk, Text, END, BOTH, W, N, E, S
import tkMessageBox as box
import tkFileDialog
import re


class DrillParser(Frame):
  
    def __init__(self, parent):
        Frame.__init__(self, parent)   
         
        self.parent = parent        
        self.initUI()
        
    def initUI(self):
      
        self.parent.title("Drill file parser")
        self.style = Style()
        self.style.theme_use("default")        
        self.pack( fill=BOTH, expand=1 )

        self.columnconfigure(1, weight=1)
        self.columnconfigure(3, pad=7)
        self.rowconfigure(3, weight=1)
        self.rowconfigure(5, pad=7)
        
        self.openBtn = Button(self, text="Open drill file", command=self.onOpen)
        self.openBtn.grid( sticky=W )

        self.txt = Text(self)
        self.txt.grid( row=1, column=0, rowspan=5, columnspan=2, sticky=E+W+S+N )
        #self.txt.pack(fill=BOTH, expand=1)

    def onOpen(self):
        #box.showerror("Error", "Could not open file")
        ftypes = [ ('Drill files', '*.drl'), ('All files', '*') ]
        dlg = tkFileDialog.Open( self, filetypes = ftypes )
        fl = dlg.show()
        
        if fl != '':
            text = self.readFile( fl )
            self.txt.insert( END, text )

    def readFile(self, filename):
        f = open( filename, "r" )
        text = self.parser( filename )
        return text

    def parser( self, fileName ):
        f = open( fileName, 'r' )
        lines = f.readlines()
        f.close()
        self.holes = {}
        # On the first pass collect all possible hole types.
        print "Looking for all possible iameters"
        for stri in lines:
            p = re.match( "(T\d{1,})C(0{0,1}\.{0,1}\d{1,})", stri )
            if p:
                k = p.group( 1 )
                v = p.group( 2 )
                print k, ": ", v
                self.holes[ k ] = [ float( v ), [] ]
        # on the second pass collect holes and sort them out.
        print "Enumerating holes and sorting them according to their diameters"
        typ  = None
        for stri in lines:
            p = re.match( "(T\d{1,})", stri )
            if ( p != None ):
                typ = p.group( 1 )
                print "New current hole type: ", typ
            else:
                p = re.match( "X(-?\d{1,}\.?\d{0,})Y(-?\d{1,}\.?\d{0,})", stri )
                if (typ != None) and (p != None):
                    #print typ
                    #print self.holes[ typ ]
                    #print self.holes[ typ ][ 0 ]
                    #print self.holes[ typ ][ 1 ]
                    x = p.group( 1 )
                    y = p.group( 2 )
                    ind = len( self.holes[ typ ][1] )
                    #print "ind: ", ind, \
                    #      ", x: ", x, \
                    #      ", y: ", y, \
                    #      ", ", type( self.holes[ typ ][1] )
                    self.holes[ typ ][1].append( [ float(x), float(y) ] )
        result = ""
        for k, v in self.holes.iteritems():
            d = v[0]
            for pt in v[1]:
                stri = "%(d)4.3f; %(x)4.3f; %(y)4.3f\n" % { "d": d, "x": abs(pt[0]), "y": abs(pt[1]) }
                result += stri
        return result

def main():
    root = Tk()
    ex = DrillParser(root)
    root.geometry("350x300+300+300")
    root.mainloop()  


if __name__ == '__main__':
    main() 




