import { Component } from '@angular/core';
import { HelloService, HelloResponse } from './hello.service';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'hello-page',
  standalone: true,
  imports: [CommonModule],
  template: `
    <h1>{{ message }}</h1>
    <p>{{ time }}</p>
    <button (click)="load()">Pobierz z backendu</button>
  `
})
export class HelloPageComponent {
  message = 'Angular działa';
  time = '';

  constructor(private helloService: HelloService) {}

  load() {
    this.helloService.getHello().subscribe((res: HelloResponse) => {
      this.message = res.message;
      this.time = res.time;
    });
  }
}