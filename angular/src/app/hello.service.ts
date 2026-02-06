import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';

export interface HelloResponse {
  message: string;
  time: string;
}

@Injectable({
  providedIn: 'root'
})
export class HelloService {

  constructor(private http: HttpClient) {}

  getHello(): Observable<HelloResponse> {
    return this.http.get<HelloResponse>('http://localhost:8080/api/hello');
  }
}