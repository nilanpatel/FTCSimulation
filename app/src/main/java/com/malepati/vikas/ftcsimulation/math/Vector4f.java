package com.malepati.vikas.ftcsimulation.math;

/**
 * Created by Vikas Malepati on 3/20/2018.
 */

public class Vector4f {

    public float x, y, z, w;

    public Vector4f() {
        set(0.0f, 0.0f, 0.0f, 0.0f);
    }

    public Vector4f(Vector4f vector) {
        set(vector.x, vector.y, vector.z, vector.w);
    }

    public Vector4f(float x, float y, float z, float w) {
        set(x, y, z, w);
    }

    public void set(float x, float y, float z, float w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
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

    public float getW() {
        return w;
    }

    public Vector4f add(Vector4f vector) {
        this.x += vector.x;
        this.y += vector.y;
        this.z += vector.z;
        this.w += vector.w;
        return this;
    }

    public Vector4f subtract(Vector4f vector) {
        this.x -= vector.x;
        this.y -= vector.y;
        this.z -= vector.z;
        this.w -= vector.w;
        return this;
    }

    public Vector4f multiply(Vector4f vector) {
        this.x *= vector.x;
        this.y *= vector.y;
        this.z *= vector.z;
        this.w *= vector.w;
        return this;
    }

    public Vector4f divide(Vector4f vector) {
        this.x /= vector.x;
        this.y /= vector.y;
        this.z /= vector.z;
        this.w /= vector.w;
        return this;
    }

    public boolean equals(Object object) {
        if (!(object instanceof Vector4f)) return false;
        Vector4f vec = (Vector4f) object;
        if (vec.getX() == this.getX() && vec.getY() == this.getY() && vec.getZ() == this.getZ() && vec.getW() == this.getW()) return true;
        return false;
    }

}
