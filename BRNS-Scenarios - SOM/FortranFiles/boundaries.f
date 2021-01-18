c      
c     SUBROUTINE boundaries
c      
      subroutine boundaries()
        include 'common_geo.inc'
        include 'common.inc'
        j = 1
          spb(1,1) = 0.1D1
          spb(2,1) = 1
          spb(3,1) = 1
          spb(4,1) = 1
          spb(5,1) = 0.1D1
          spb(6,1) = 1
          spb(7,1) = 1
          ibc(1,1) = 0
          ibc(2,1) = 0
          ibc(3,1) = 0
          ibc(4,1) = 0
          ibc(5,1) = 0
          ibc(6,1) = 0
          ibc(7,1) = 0
        j = nx
          spb(1,2) = 0.D0
          spb(2,2) = 0
          spb(3,2) = 0
          spb(4,2) = 0
          spb(5,2) = 0.D0
          spb(6,2) = 0
          spb(7,2) = 0
          ibc(1,2) = 1
          ibc(2,2) = 1
          ibc(3,2) = 1
          ibc(4,2) = 1
          ibc(5,2) = 0.1D1
          ibc(6,2) = 1
          ibc(7,2) = 1
      end
