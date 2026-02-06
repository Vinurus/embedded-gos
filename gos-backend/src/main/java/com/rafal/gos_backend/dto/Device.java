package com.rafal.gos_backend.dto;


public class Device {
    private String id;
    private String name;
    private String status;

    public Device(String id, String name, String status) {
        this.id = id;
        this.name = name;
        this.status = status;
    }

    public String getId() { return id; }
    public String getName() { return name; }
    public String getStatus() { return status; }
}