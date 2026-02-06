package com.rafal.gos_backend;

import com.rafal.gos_backend.dto.HelloResponse;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.time.LocalDateTime;

@RestController
public class HelloController {

    @GetMapping("/api/hello")
    public HelloResponse hello() {
        return new HelloResponse(
                "Backend mówi: siema Rafał!",
                LocalDateTime.now().toString()
        );
    }
}