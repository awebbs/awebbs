import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { UserProfileComponent } from './user-profile/user-profile.component';
import { DashboardComponent } from './dashboard/dashboard.component';
import { UserDetailComponent } from './user-detail/user-detail.component';
import { PageNotFoundComponent } from './page-not-found/page-not-found.component';

const routes: Routes = [
  { path: 'users', component: UserProfileComponent },
  { path: 'dashboard', component: DashboardComponent },
  { path: '', redirectTo: './dashboard', pathMatch: 'full' },
  { path: 'detail/:id', component: UserDetailComponent },
  { path: '**', component: PageNotFoundComponent },

];

@NgModule({
  imports: [ RouterModule.forRoot(routes) ],
  exports: [ RouterModule ]
})

export class AppRoutingModule { }
