package com.rafal.gos_backend;



import com.rafal.gos_backend.dto.Device;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class DeviceController {

    @GetMapping("/api/devices")
    public List<Device> getDevices() {
        return List.of(
                new Device("1", "ESP32 1", "online"),
                new Device("2", "ESP32 2", "offline")
        );
    }
}