import { Routes } from '@angular/router';
import { HelloPageComponent } from './hello-page.component';

export const routes: Routes = [
  { path: '', component: HelloPageComponent },
  { path: 'hello', component: HelloPageComponent }
];