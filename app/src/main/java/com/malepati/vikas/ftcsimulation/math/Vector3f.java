package com.malepati.vikas.ftcsimulation.math;

/**
 * Created by Vikas Malepati on 3/20/2018.
 */

public class Vector3f {

    public float x, y, z;

    public Vector3f() {
        set(0.0f, 0.0f, 0.0f);
    }

    public Vector3f(Vector3f vector) {
        set(vector.x, vector.y, vector.z);
    }

    public Vector3f(float x, float y, float z) {
        set(x, y, z);
    }

    public void set(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    public float getZ() {
        return z;
    }

    public Vector3f add(Vector3f vector) {
        this.x += vector.x;
        this.y += vector.y;
        this.z += vector.z;
        return this;
    }

    public Vector3f subtract(Vector3f vector) {
        this.x -= vector.x;
        this.y -= vector.y;
        this.z -= vector.z;
        return this;
    }

    public Vector3f multiply(Vector3f vector) {
        this.x *= vector.x;
        this.y *= vector.y;
        this.z *= vector.z;
        return this;
    }

    public Vector3f divide(Vector3f vector) {
        this.x /= vector.x;
        this.y /= vector.y;
        this.z /= vector.z;
        return this;
    }

    public float getMagnitude() {
        return (float) Math.sqrt(x * x + y * y + z * z);
    }

    public Vector3f getNormalized() {
        float length = getMagnitude();
        return new Vector3f(x / length, y / length, z / length);
    }

    public static float getDistance(Vector3f v0, Vector3f v1) {
        double x = v0.getX() - v1.getX();
        double y = v0.getY() - v1.getY();
        double z = v0.getZ() - v1.getZ();
        return (float) Math.sqrt(x * x + y * y + z * z);
    }

    public static float getDot(Vector3f v0, Vector3f v1) {
        return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
    }

    public boolean equals(Object object) {
        if (!(object instanceof Vector3f)) return false;
        Vector3f vec = (Vector3f) object;
        if (vec.getX() == this.getX() && vec.getY() == this.getY() && vec.getZ() == this.getZ()) return true;
        return false;
    }

}
