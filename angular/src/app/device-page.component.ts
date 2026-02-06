import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { DeviceService, Device } from './device.service';

@Component({
  selector: 'device-page',
  standalone: true,
  imports: [CommonModule],
  template: `
    <h1>Urządzenia</h1>

    <button (click)="load()">Załaduj urządzenia</button>

    <ul>
      <li *ngFor="let d of devices">
        <strong>{{ d.name }}</strong> — {{ d.status }}
      </li>
    </ul>
  `
})
export class DevicePageComponent {
  devices: Device[] = [];

  constructor(private deviceService: DeviceService) {}

  load() {
    this.deviceService.getDevices().subscribe(res => {
      this.devices = res;
    });
  }
}