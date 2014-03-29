import math

class vector(object):
    """
    Represents a three dimension vector in it's i, j, and k components.
    """
    def __init__(self, i, j, k):
        self.i = float(i)
        self.j = float(j)
        self.k = float(k)

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        return "%.2fi + %.2fj + %.2fk" %(self.i, self.j, self.k)

    def __add__(self, other):
        """
        Adds the components of the vectors.
        """
        if isinstance(other, vector):
            ti = self.i + other.i
            tj = self.j + other.j
            tk = self.k + other.k
            return vector(ti, tj, tk)

    def __mul__(self, scalar):
        """
        Allows a scalar to multiply into the vector or multiplies the vectors
        components together.
        """
        if isinstance(scalar, int) or isinstance(scalar, float):
            ti = self.i * scalar
            tj = self.j * scalar
            tk = self.k * scalar
        elif isinstance(scalar, vector):
            ti = self.i * scalar.i
            tj = self.j * scalar.j
            tk = self.k * scalar.k
        return vector(ti, tj, tk)


    def magnitude(self):
        """
        Returns the magnitude.
        """
        return math.sqrt(pow(self.i, 2) + pow(self.j, 2) + pow(self.k, 2))

    def two_angles(self):
        """
        Returns the horizontal angle from the x axis and the vertical angle from
        the x-y plane in the form of a tuple of the form(horizontal, vertical).
        """
        vertical = math.degrees(math.asin(self.k / self.magnitude()))
        horizontal = math.degrees(math.atan(self.j / self.i))
        return (horizontal, vertical)

    def three_angles(self):
        """
        Returns the directional cosines of the vector from each axis in a tuple
        of the form (x, y, z).
        """
        x = math.degrees(math.acos(self.i / self.magnitude()))
        y = math.degrees(math.acos(self.j / self.magnitude()))
        z = math.degrees(math.acos(self.k / self.magnitude()))
        return (x, y, z)

i = vector(1, 0, 0)
j = vector(0, 1, 0)
k = vector(0, 0, 1)

def vector_two_angles(mag, horizontal, vertical):
    """
    Returns a vector given the magnitude and the horizontal angle from the
    x-axis and the vertical angle from the x-y plane.
    """
    a = mag * math.cos(math.radians(vertical))
    z = mag * math.sin(math.radians(vertical))
    x = a * math.cos(math.radians(horizontal))
    y = a * math.sin(math.radians(horizontal))
    return vector(x, y, z)

def vector_three_angles(mag, a, b, c):
    """
    Returns a vector given the magnitude and the directional cosines.
    """
    x = mag * math.cos(math.radians(a))
    y = mag * math.cos(math.radians(b))
    z = mag * math.cos(math.radians(c))
    return vector(x, y, z)

def cross(r, f):
    """
    Returns the resulting vector from the cross product of r x f.
    """
    x = (r.j * f.k) - (f.j * r.k)
    y = (f.i * r.k) - (r.i * f.k)
    z = (r.i * f.j) - (f.i * r.j)
    return vector(x, y, z)

def dot(v):
    """
    Returns the dot product of the list of vectors.
    """
    ti = 1
    tj = 1
    tk = 1
    for vector in v:
        ti *= vector.i
        tj *= vector.j
        tk *= vector.k
    return ti + tj + tk

def unit_vector(u):
    """
    Returns a unit vector from the vector passed into the function.
    """
    x = u.i / u.magnitude()
    y = u.j / u.magnitude()
    z = u.k / u.magnitude()
    return vector(x, y, z)

def triple_scalar_product(u, r, f):
    """
    Returns the torque projected along a line.
    """
    return dot(unit_vector(u), cross(r, f))

def force_along_a_line(r, f):
    """
    Returns the force projected along a line.
    """
    return unit_vector(r) * f

