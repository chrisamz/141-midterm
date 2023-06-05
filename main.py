import numpy as np
import matplotlib.pyplot as plt

# Define Constants
G = 6.67430e-11     # Gravitational constant
m_A = 1.0e11        # Mass of galaxy A
m_B = 1.0e11        # Mass of galaxy B
R_min = 25          # Pericenter distance
e = 0.6             # Eccentricity
t_init = -16.4      # Initial time
t_final = 6.086     # Final time
dt = 0.01           # Time step

def gravitational_force(m1, m2, r):
    return G * m1 * m2 / (r**2)

def acceleration(m1, m2, r, pos):
    return gravitational_force(m1, m2, r) * pos/ (m1 * r)

def leapfrog_integration(pos, vel, acc, dt):
    pos += vel * dt + 0.5 * acc * dt**2
    vel += 0.5 * acc * dt
    return pos, vel

def simulate_collision():
    np.seterr(divide='ignore')

    #Initial Conditions
    t = t_init
    test_particles_A = []
    test_particles_B = []

    # Initial position of galaxy A
    pos_A = np.array([0.7 * R_min, 0])  
    # Initial velocity of galaxy A
    vel_A = np.array([0, np.sqrt((1 + np.e) * G * m_B / (0.7 * R_min))]) 
    # Initial position of galaxy B
    pos_B = np.array([-0.7 * R_min, 0])  
    # Initial velocity of galaxy B
    vel_B = np.array([0, -np.sqrt((1 + np.e) * G * m_A / (0.7 * R_min))])

    # Vectorize Functions
    vec_norm = np.vectorize(np.linalg.norm)
    vec_acceleration = np.vectorize(acceleration)
    vec_leapfrog_integration = np.vectorize(leapfrog_integration)

    # Simulate
    while(t <= t_final):
        try:
            r_A, r_B = vec_norm(np.array([pos_A, pos_B]))
            a_A, a_B = vec_acceleration(np.array([m_A, m_B]), np.array([m_B, m_A]), np.array([r_A, r_B]), np.array([pos_A, pos_B]))
            a = vec_leapfrog_integration(np.array([pos_A, pos_B]), np.array([vel_A, vel_B]), np.array([a_A, a_B]), dt)
            test_particles_A.append(pos_A.copy())
            test_particles_B.append(pos_B.copy())
            t += dt
        except ZeroDivisionError as e:
            pass
    else:
        print("What happened")

if __name__ == "__main__":
    simulate_collision()