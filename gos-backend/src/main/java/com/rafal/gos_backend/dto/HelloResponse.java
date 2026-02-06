package com.rafal.gos_backend.dto;

public class HelloResponse {
    private String message;
    private String time;

    public HelloResponse(String message, String time) {
        this.message = message;
        this.time = time;
    }

    public String getMessage() {
        return message;
    }

    public String getTime() {
        return time;
    }
}