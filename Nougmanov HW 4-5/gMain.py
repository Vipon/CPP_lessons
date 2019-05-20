from gObject import *

from gRectangle import *
from gSquare import *

from gEllipse import *
from gCircle import *

from gTriangle import *
from gSegment import *

x = gObject(2,3)

x = triangle(1,2,3)
x = circle(2,4)
x.axial_tension(2,1)
x.draw()